/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:19:17 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/07 00:19:25 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char    *tmp_file_name(char *format, int id)
{
    char *id_str;
    char *result;

    id_str = ft_itoa(id);
    result = ft_strjoin(format, id_str);
    free(id_str);
    return (result);
}

int     prepare_heredoc(t_data *data, char *filename, char *end)
{
    int     len;
    bool    do_eval;
    int     fd;
    char    *line;

    len = ft_strlen(end);
    do_eval = false;
    if (len > 2 && end[len - 2] == '"' && end[len - 1] == '"')
        end[len - 2] = 0;
    else
        do_eval = true;

    fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (fd < 0)
        return (0);
    while (1)
    {
        line = readline("> ");
        if (ft_strncmp(line, end, len + 1) == 0) // TODO: use simply `ft_strcmp()`
        {
            free(line);
            break;
        }
        if (do_eval)
            line = eval(line, data);
        write(fd, line, ft_strlen(line));
        write(fd, "\n", 1);
        free(line);
    }
    close(fd);
    return (1);
}

int     prepare_redirections(t_data *data)
{
    int i;

    i = 0;
    while (i < data->nb_processes)
    {
        if (!data->process[i].input && data->process[i].heredoc)
        {
            data->process[i].input = tmp_file_name("/tmp/minishell.", i);
            if (!prepare_heredoc(data, data->process[i].input, data->process[i].heredoc))
            {
                close_redirection_fds(data);
                return (0);
            }
        }
        if (data->process[i].input)
        {
            data->process[i].fd_input = open(data->process[i].input, O_RDONLY);
            if (data->process[i].fd_input < 0)
            {
                close_redirection_fds(data);
                return (0);
            }
        }
        if (data->process[i].output)
        {
            if (data->process[i].append)
                data->process[i].fd_output = open(data->process[i].output, O_CREAT | O_RDWR |O_APPEND, 0644);
            else
                data->process[i].fd_output = open(data->process[i].output, O_CREAT | O_RDWR | O_TRUNC, 0644);
            if (data->process[i].fd_output < 0)
            {
                close_redirection_fds(data);
                return (0);
            }
        }
        i++;
    }
    return (1);
}

void    close_redirection_fds(t_data *data)
{
    int i;

    i = 0;
    while (i < data->nb_processes)
    {
        if (data->process[i].fd_input > -1)
        {
            close(data->process[i].fd_input);
            data->process[i].fd_input = -1;
        }
        if (data->process[i].fd_output > -1)
        {
            close(data->process[i].fd_output);
            data->process[i].fd_output = -1;
        }
        i++;
    }
}
