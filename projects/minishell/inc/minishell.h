/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:41:46 by mkhabou           #+#    #+#             */
/*   Updated: 2022/02/06 13:41:51 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <dirent.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/resource.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termcap.h>
# include <termios.h>
# include <unistd.h>
# include <stdbool.h>

# define NF ": command not found"
# define ISD ": is a directory"
# define NSFD ": No such file or directory"
# define MAX_ALLOC 1000
# define ERR_OPE "Operation error!\n"

extern int	g_exit_status;

typedef struct s_process
{
	char	**params;
	char	*input;
	char	*output;
	char	*heredoc;
	bool	append;
	int		fd_input;
	int		fd_output;
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
char	*my_getenv(char *name, char **my_envp);
char	**dup_envp(char *envp[]);
void	ft_echo(char **complete_cmd);
void	ft_pwd(char **my_envp);
void	ft_env(char **complete_cmd, char **my_envp);
void	ft_cd(char **complete_cmd, t_data *data);
void	ft_exit(char **complete_cmd);
void	ft_unset(char **complete_cmd, t_data *data);
void	ft_export(char **complete_cmd, t_data *data);
void	sort_print(t_data *data);
void	ft_sort_params(char **tab, int size);
int		check_env(char *s);
char	**find_path(char **my_envp);
char	**find_cmds(char **complete_cmd, t_data *data);
char	*test_cmd_path(char **path, char *cmd, int *dir);
int		find_built_ins(char *cmd);
void	exec_cmds(t_data *data);
void	exec_pipes(t_data *data, int nb_pipes);
void	change_env_value(t_data *data, char *var, char *new_value);
void	free_data(t_data *data);
void	error_fct(t_data *data, char *msg, int exit_value);
int		ft_strfind(char c, char *s);
void	main_sigint_handler(int signum);
void	child_sigint_handler(int signum);
void	remove_env(char *var, t_data *data);
/* parsing */
int		str_err(char *err, int i);
int		skip_spaces(char	*str, int i);
bool	parse_process(char *s, t_process *process, t_data *data);
char	**split(char *s, char delimiter);
char	*resolve_env(char *s, t_data *data);
int		find_pos(const char *haystack, const char *needle, int len);
char	*strjoin(char const *s1, char const *s2);
char	**alloc_t(void);
void	free_t(char **arr);
int		count_elements(void **arr);
char	*eval(char *s, t_data *data);
/* redirections */
int     prepare_redirections(t_data *data);
void    close_redirection_fds(t_data *data);

#endif