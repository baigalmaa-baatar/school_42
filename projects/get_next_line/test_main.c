#include "get_next_line.h"

int main(int argc, char **argv)
{
	char *line;
	int fd1;
	//   int   fd2;

	if (argc < 2)
		return (-1);
	fd1 = open(argv[1], O_RDONLY);
	//   fd2 = open(argv[2], O_RDONLY);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	// //   get_next_line(fd2, &line);
	// printf("%s\n", line);
	// //   get_next_line(fd2, &line);
	// printf("%s\n", line);
	// get_next_line(fd1, &line);
	// printf("%s\n", line);
	// //   get_next_line(fd2, &line);
	// printf("%s\n", line);
	// get_next_line(fd1, &line);
	// printf("%s\n", line);
	// //   get_next_line(fd2, &line);
	// printf("%s\n", line);
	return (0);
}