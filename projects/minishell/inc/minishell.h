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
#include <stdbool.h>

# define NF ": command not found"
# define MAX_ALLOC 1000
#define ERR_OPE "Operation error!\n"

extern int g_exit_status;

typedef struct s_process
{
	char	**params;
	char	*input;
	char	*output;
	char	*heredoc;
	bool	append;
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
	int			nb_processes;
}				t_data;


void	parse(t_data *data);
char 	*my_getenv(char *name, char **envp);
void	ft_echo(char **complete_cmd);
void	ft_pwd(void);
void	ft_env(char **complete_cmd, char **envp);
void	ft_cd(char **complete_cmd, t_data *data);
void	ft_exit(char **complete_cmd);
char	**find_path(char **my_envp);
char	**find_cmds(char **complete_cmd, t_data *data);
char	*test_cmd_path(char **path, char *cmd);
int		find_built_ins(char *cmd);
void	exec_cmds(t_data *data);
void	exec_pipes(t_data *data, int nb_pipes);
void	free_data(t_data *data);
void	error_fct(t_data *data, char *msg, int exit_value);
/* parsing */
int		str_err(char *err, int i);
int		skip_spaces(char	*str, int i);
// char	**split_param(char *s, t_data *data); //deleted
bool	parse_process(char *s, t_process *process, t_data *data);
char	**split(char *s, char delimiter);
char	*resolve_env(char *s, t_data *data);
int		find_pos(const char *haystack, const char *needle, int len);
char	*strjoin(char const *s1, char const *s2);
// char	**split_pipe(char *s, int *nb_processes); //deleted
char	**alloc_t(void);
void 	free_t(char **arr);
int		count_elements(void **arr);

#endif