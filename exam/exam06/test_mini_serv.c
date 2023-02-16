#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <arpa/inet.h>
#include <errno.h>

#include <string.h>
#include <unistd.h>

typedef struct s_server
{
    int server_socket;
    int max_id;
    int max_fds;
    struct sockaddr_in servaddr;
    fd_set sockets;
    fd_set read_set;
    fd_set write_set;

} t_server;

typedef struct s_client
{
    int fd;
    int id;
    char *message_buff;
    struct s_client *next;

} t_client;

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

void fatal(int id)
{
    write(2, "Fatal error\n", strlen("Fatal error\n"));
    (void)id;
    exit(1);
}

void send_to_all_clients(t_server *s, t_client *client, char *text, int fd)
{
    while (client != 0)
    {
        if (client->fd != fd && FD_ISSET(client->fd, &s->write_set))
            send(client->fd, text, strlen(text), MSG_DONTWAIT);
        client = client->next;
    }
}

t_client* client_disconnection(t_server *s, t_client *start, t_client *connected_socket)
{
    t_client *it;
    t_client *prior;
    char buffer[100];

    it = start;
    prior = 0;
    sprintf(buffer, "server: client %d just left\n", connected_socket->id);
    send_to_all_clients(s, start, buffer, connected_socket->fd);
    while(it != 0)
    {
        if (it->id == connected_socket->fd)
        {
            if (prior == 0)
                start = start->next;
            else
                prior->next = prior->next->next;
            break;
        }
        prior = it;
        it = it->next;
    }
    FD_CLR(connected_socket->fd, &s->sockets);
    close(connected_socket->fd);
    free(connected_socket->message_buff);
    free(connected_socket);
    return (start);
}

t_client* client_message(t_server *s, t_client *start, t_client *connected_socket)
{
    char message[1000000];
    char buffer[1000000];
    char line[1000000];
    int len;
    int i;
    int l;

    i = 0;
    l = 0;
    if ((len = recv(connected_socket->fd, message, sizeof(message) - 1, MSG_DONTWAIT)) == 0)
        start = client_disconnection(s, start, connected_socket);
    else if (len == -1)
        return (start);
    else
    {
        message[len] = 0;
        while (message[i])
        {
            line[l] = message[i];
            if (message[i] == '\n')
            {
                line[l + 1] = 0;
                if (connected_socket->message_buff != 0)
                {
                    sprintf(buffer, "client %d: %s%s", connected_socket->id, connected_socket->message_buff, line);
                    free(connected_socket->message_buff);
                    connected_socket->message_buff = 0;
                }
                else
                    sprintf(buffer, "client %d: %s", connected_socket->id, line);
                send_to_all_clients(s, start, buffer, connected_socket->fd);
                l = -1;
            }
            i++;
            l++;
        }
        if (message[i - 1] != '\n')
        {
            line[l] = 0;
            if ((connected_socket->message_buff = str_join(connected_socket->message_buff, line)) == 0)
                fatal(6);
        }
    }
    return (start);
}

t_client* client_connection(t_server *s, t_client *client)
{
    int new_connection;
    char buffer[100];
    t_client *new;
    t_client *curr;
    socklen_t len;

    curr = client;
    len = sizeof(s->servaddr);
    if ((new_connection = accept(s->server_socket, (struct sockaddr *)&s->servaddr, &len) == -1))
        return (client);
    if (new_connection > s->max_fds)
        s->max_fds = new_connection;
    FD_SET(new_connection, &s->sockets);
    if ((new = malloc(sizeof(t_client))) == 0)
        fatal(5);
    new->fd = new_connection;
    new->id = s->max_id++;
    new->next = 0;
    new->message_buff = 0;
    if (client == 0)
        client = new;
    else
    {
        while (curr->next != 0)
            curr = curr->next;
        curr->next = new;
    }
    sprintf(buffer, "server: client %d just arrived\n", new->id);
    send_to_all_clients(s, client, buffer, new_connection);
    return (client);
}

void launch_server(t_server s)
{
    t_client *client;
    t_client *curr;

    client = 0;
    s.max_id = 0;
    s.max_fds = s.server_socket;
    FD_ZERO(&s.sockets);
    FD_SET(s.server_socket, &s.sockets);
    while (1)
    {
        s.read_set = s.sockets;
        s.write_set = s.sockets;
        curr = client;
        if (select(s.max_fds + 1, &s.read_set, &s.write_set, 0, 0) == -1)
            fatal(4);
        if (FD_ISSET(s.server_socket, &s.read_set))
        {
            client = client_connection(&s, client);
            continue;
        }
        while (curr)
        {
            if (FD_ISSET(curr->fd, &s.read_set))
                client = client_message(&s, client, curr);
            curr = curr->next;
        }
    }
}

void setup_server(t_server *s, int port_number)
{
    // assign IP, PORT
    s->servaddr.sin_family = AF_INET;
    s->servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
    s->servaddr.sin_port = htons(port_number);
    // socket create and verification
    if ((s->server_socket = socket(AF_INET, SOCK_STREAM, 0) == -1))
        fatal(1);

    // binding newly created socket to given IP and verification
    if ((bind(s->server_socket, (const struct sockaddr *)&s->servaddr, sizeof(s->servaddr))) != 0)
        fatal(2);

    // listen
    if (listen(s->server_socket, 10) != 0)
        fatal(3);
}

int main(int argc, char **argv)
{
    t_server s;

    if (argc != 2)
        write(2, "Wrong number of arguments\n", sizeof("Wrong number of arguments\n"));
    setup_server(&s, atoi(argv[1]));
    launch_server(s);
    return (0);
}