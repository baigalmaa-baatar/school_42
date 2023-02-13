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

client_message(t_server *s, t_client *start, t_client *connected_socket)
{
    char message[1000000];
    char buffer[1000000];
    char line[1000000];
    int len;
    int i;
    int l;

    i = 0;
    l = 0;
    if ((len = recv(connected_socket, buffer, sizeof(buffer), MSG_DONTWAIT)) == 0)
    {
        start = disconnet_client(s, connected_socket);
        return (start);
    }
    if (len = -1)
        fatal(6);
    else
    {
        message[len] = 0;
        while (message[i])
        {
            line[l] = message[i];
            if (message[i] == '\n')
            {
                line[l + 1] = 0;
                if ()
                else
                {
                    sprintf(buffer, );
                    send_to_all_clients();
                }
            }
            i++;
            l++;
        }
    }
}

client_connection(t_server *s, t_client *client)
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
    if (s->server_socket = socket(AF_INET, SOCK_STREAM, 0) == -1)
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