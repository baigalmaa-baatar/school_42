#include <stdio.h>

typedef struct s_server
{
    int server_socket;

} t_server;

typedef struct s_client
{
    int fd;
    int id;
    char *message_buff;
    struct s_client *next;

} t_client;


int main(int argc, char **argv)
{
	t_server s;

    if (argc != 2)
        write(2, "Wrong number of arguments\n", sizeof("Wrong number of arguments\n"));
	setup_server(&s, atoi(argv[1]));
	launch_server(s);
	return (0);
}