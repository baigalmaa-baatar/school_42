#ifndef MINISHELL_H
# define MINISHELL_H

#include "../libft/libft.h"
#include <dirent.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <termcap.h>
#include <termios.h>
#include <unistd.h>

# define NF ": command not found"

extern int exit_status;

typedef struct s_process
{
	char	**params;
	//char	*redirect;
}	t_process;

typedef struct s_elements
{
	int		*child;
	int		*built_in;
	int		**pipe_fd;
}			t_elements;

void	parse(char *line, char *envp[]);
void	ft_echo(char **complete_cmd);
void	ft_pwd(void);
void	ft_env(char *envp[]);
void	ft_cd(char **complete_cmd);
void	ft_exit(char **complete_cmd);
char	**find_path(void);
char	**find_cmds(char **complete_cmd, char **path);
char	*test_cmd_path(char **path, char *cmd);
int		find_built_ins(char *cmd);
void	exec_cmds(t_process *process, char **path, char *envp[]);
void	exec_pipes(t_process *process, char **path, char *envp[], int nb_pipes);
void	error_fct(char *msg, int exit_value);
/* parsing */
int		str_err(char *err, int i);
int		is_space(char	*str, int i);
char	**split_param(char *s);
char	*resolve_env(char *s);
int		find_pos(const char *haystack, const char *needle, int len);
char	*strjoin(char const *s1, char const *s2);
char	**split_pipe(char *s);
char	**alloc_t(void);

#endif
