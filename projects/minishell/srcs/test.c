#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <termcap.h>
#include <signal.h>
#include <sys/types.h>
#include <dirent.h>
#include <readline/readline.h>
#include <readline/history.h>

int	ft_putchar(int c)
{
	char a = c;
	write(1, &a, 1);
	return (0);
}

void sig_handler(int signum)
{
	printf("\nInside handler function\n");
	printf("signum = %d\n", signum);
	signal(SIGINT, SIG_DFL);
}

int main()
{
	int		i;
	char	*line;
	char	*prompt;
	struct termios termios_p;
	char *bp = NULL;
	char *area = NULL;

	i = 0;
	prompt = "Minishell > ";
	printf("Fd connecté à un terminal : %d; Pathname : %s\n", isatty(0), ttyname(0));
	printf("Fd connecté à un terminal : %d; Pathname : %s\n", isatty(3), ttyname(3));
	printf("ttyslot = %d\n", ttyslot());
	printf("getenv PATH = %s\n", getenv("PATH"));
	tcgetattr(1, &termios_p);
	tcsetattr(1, TCSANOW, &termios_p);
	printf("return tgetent = %d\n", tgetent(bp, getenv("TERM")));
	printf("return tgetflag = %d\n", tgetflag("li"));
	printf("return tgetnum = %d\n", tgetnum("co"));
	char	*ret1 = tgetstr("md", &area);
	char	*ret2 = tgetstr("me", &area);
//	tputs(tgoto(tgetstr("cm", NULL), 20, 20), 1, ft_putchar);
	printf("getcwd : %s\n", getcwd(NULL, 0));
	while (i < 5)
	{
  //	signal(SIGINT, sig_handler);
		line = readline(prompt);
		tputs(ret1, 1, ft_putchar);
		printf("La ligne lue: \"%s\"\n", line);
		if (*line)
			add_history(line);
		free(line);
		line = NULL;
		i++;
		tputs(ret2, 1, ft_putchar);
	}
	
	DIR *folder;
    struct dirent *entry;
    int files = 0;

    folder = opendir(".");
    if(folder == NULL)
    {
        perror("Unable to read directory");
        return(1);
    }
    while( (entry=readdir(folder)) )
    {
        files++;
        printf("File %3d: %s\n",
                files,
                entry->d_name
              );
    }
    closedir(folder);
	return (0);
}