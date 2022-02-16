/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:41:46 by mkhabou           #+#    #+#             */
/*   Updated: 2022/02/12 22:43:31 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <unistd.h>
# include <stdbool.h>

# define NF ": command not found"
# define ISD ": Is a directory"
# define MAX_ALLOC 1000
# define ERR_OPE "Operation error!\n"

extern int	g_exit_status;

typedef struct s_array
{
	size_t	length;
	size_t	capacity;
	void	**elements;
}			t_array;

typedef struct s_process
{
	char	**params;
	t_array	redirs;
	int		fd_input;
	int		fd_output;
	bool	error;
}			t_process;

typedef struct s_elements
{
	int		*child;
	int		*built_in;
	int		**pipe_fd;
}			t_elements;

typedef struct s_data
{
	char				*line;
	char				**path;
	char				**my_envp;
	t_process			*process;
	int					nb_processes;
	struct sigaction	sigint;
	struct sigaction	sigquit;
}						t_data;

void	parse(t_data *data);
void	init_process(t_process *process);
void	init_signals(t_data *data);
char	*my_getenv(char *name, char **my_envp);
char	**dup_envp(char *envp[]);
char	**find_path(char **my_envp);
void	free_data(t_data *data);
void	free_process(t_data *data, int i);
void	free_processes(t_data *data);
void	error_fct(t_data *data, char *msg, int exit_value);
void	error_fct2(char *msg, int exit_value);
void	error_fct3(char *msg, char *err_str, int exit_value);
void	error_fct4(char *msg, int exit_value);
void	*my_malloc(size_t size);
void	main_sigint_handler(int signum);
void	child_sigquit_handler(int signum);
void	change_env_value(t_data *data, char *var, char *new_value);
int		special_putchar(char c, int fd);
int		special_putendl(char *s, int fd);
int		special_putstr(char *s, int fd);
int		special_mtp_putstr(char *s1, char *s2, char *s3, int fd);

/* built-ins */
void	ft_echo(char **complete_cmd);
void	ft_pwd(char **my_envp);
void	ft_env(char **complete_cmd, char **my_envp);
void	ft_cd(char **complete_cmd, t_data *data);
void	ft_unset(char **complete_cmd, t_data *data);
void	ft_export(char **complete_cmd, t_data *data);
void	ft_exit(char **complete_cmd, t_data *data);
void	sort_print(t_data *data);
void	ft_sort_params(char **tab, int size);
int		check_env(char *s);
void	remove_env(char *var, t_data *data);
void	add_env(char *var, t_data *data, int pos_equal);
int		check_env_ex(char *s);
char	**alloc_envs(int size, char **envs);

/* parsing */
int		trim(char *s);
int		str_err(char *err, int i);
char	*new_string(int capacity);
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
int		ft_strcmp(char *s1, char *s2);
char	*scan_single_quoted(char *s, int *i);
char	*scan_double_quoted(char *s, int *i);
char	*scan_unquoted(char *s, int *i);
bool	is_char_in(char ch, char *delimiters);
int		locate_chars(char *s, char *delimiters);
int		locate_char(char *s, char delimiter);
char	*eval(char *s, t_data *data);
void	trim_right(char *s);
void	copy_then_free(char *src, int *i, char *dst);
bool	env_char(char c);
char	*free_res(char *res);

/* redirections */
bool	only_redir(char *s);
int		parse_redirection(char *s, int i, t_process *process, t_data *data);
void	prepare_redirections(t_data *data);
void	close_redirection_fds(t_data *data);
int		prepare_heredoc(t_data *data, char *filename, char *end, bool do_eval);
void	end_heredoc(char *end);
bool	all_space(char *s);
int		validate_redir(t_process *process);
int		prepare_redirs(t_data *data, int process_id);
void	remove_faulty_processes(t_data *data);

/* execution */
int		find_built_ins(char *cmd);
char	*test_cmd_path(char **path, char *cmd, int slash);
char	**find_cmds(char **complete_cmd, t_data *data);
void	exec_cmds(t_data *data);
void	exec_pipes(t_data *data, int nb_pipes);
void	malloc_elements(t_data *data, t_elements *elements, int nb_pipes);
void	check_all_cmds(t_data *data, t_elements *elements, int nb_pipes);
void	free_elements(t_elements *elements, int nb_pipes);
void	close_fds(t_data *data, int **pipe_fd, int index);
void	first_process(t_data *data, t_elements *elements, int i);
void	middle_process(t_data *data, t_elements *elements, int i);
void	last_process(t_data *data, t_elements *elements, int i);
void	dup_fds(t_data *data, int *stdin_copy, int *stdout_copy);
void	restore_fds(int stdin_copy, int stdout_copy);

/* array */
t_array	new_array(void);
void	array_append(t_array *arr, void *new_element);
void	delete_array(t_array *arr);

#endif