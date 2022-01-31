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
# define MAX_ALLOC 1000
#define ERR_OPE "Operation error!\n"

extern int exit_status;

typedef struct s_process
{
	char	**params;
	//char	*redirect;
}			t_process;

typedef struct s_elements
{
	int		*child;
	int		*built_in;
	int		**pipe_fd;
}			t_elements;

typedef struct s_data
{
	char		*line;
	char		**path;
	char		**my_envp;
	t_process	*process;
}				t_data;


void	parse(t_data *data);
void	ft_echo(char **complete_cmd);
void	ft_pwd(t_data *data);
void	ft_env(char *envp[]);
void	ft_cd(char **complete_cmd);
void	ft_exit(char **complete_cmd);
char	**find_path(void);
char	**find_cmds(char **complete_cmd, char **path);
char	*test_cmd_path(char **path, char *cmd);
int		find_built_ins(char *cmd);
void	exec_cmds(t_data *data);
void	exec_pipes(t_data *data, int nb_pipes);
void	free_data(t_data *data);
void	error_fct(t_data *data, char *msg, int exit_value);
/* parsing */
int		str_err(char *err, int i);
int		is_space(char	*str, int i);
char	**split_param(char *s);
char	*resolve_env(char *s);
int		find_pos(const char *haystack, const char *needle, int len);
char	*strjoin(char const *s1, char const *s2);
char	**split_pipe(char *s, int *nb_processes);
char	**alloc_t(void);
void 	free_t(char **arr);

#endif