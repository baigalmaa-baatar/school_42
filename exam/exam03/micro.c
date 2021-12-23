/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:02:37 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/23 19:02:38 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <stdbool.h>

#define ERR_ARG "Error: argument\n"
#define ERR_OPE "Error: Operation file corrupted\n"

typedef struct s_config
{
    int width;
    int height;
    char background;
}   t_config;

typedef struct s_shape
{
    char type;
    float x;
    float y;
    float width;
    float height;
    char c;
}   t_shape;

size_t  ft_strlen(char *str)
{
    size_t i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

int str_err(char *str, int ret)
{
    write (1, str, ft_strlen(str));
    return (ret);
}

int clear_all(FILE *file, char *canvas)
{
    fclose(file);
    if (canvas)
        free(canvas);
    return (1);
}

int is_inside_limit(int val)
{
    if (val > 0 && val <=300)
        return (1);
    return (0);
}

char    *create_canvas(FILE *file, t_config *config)
{
    char *buff = NULL;
    int ret_scanf;

    ret_scanf = fscanf(file, "%d %d %c\n", &config->width, &config->height, &config->background);
    if (ret_scanf == 3 && is_inside_limit(config->width) && is_inside_limit(config->height))
    {
        buff = (char *)calloc(config->width * config->height + 1, 1);
        buff = memset(buff, config->background, config->width * config->height);
    }
    return (buff);
}

static int  is_in_shape(float x, float y, t_shape *tmp)
{
    float e = 1.00000000;

    if (x < tmp->x || x > (tmp->x + tmp->width) || y < tmp->y || y > (tmp->y + tmp->height))
        return (0);
    if (x - tmp->x < e || (tmp->x + tmp->width - x) < e || y - tmp->y < e || (tmp->y + tmp->height - y) < e)
        return (2);
    return (1);
}

static void put_shapes_on_canvas(t_config *config, char *buff, t_shape *tmp)
{
    int x;
    int y;
    int flag;
    
    y = 0;
    while (y < config->height)
    {
        x = 0;
        while (x < config->width)
        {
            flag = is_in_shape((float)x, (float)y, tmp);
            if ((flag == 2 && tmp->type == 'r') || (flag && tmp->type == 'R'))
                buff[config->width * y + x] = tmp->c;
            x++;
        }
        y++;
    }
}

static bool do_shapes(FILE *file, t_config *config, char *buff)
{
    int ret_scanf;
    t_shape tmp;

    while ((ret_scanf = fscanf(file, "%c %f %f %f %f %c\n", &tmp.type, &tmp.x, &tmp.y, &tmp.width, &tmp.height, &tmp.c)) == 6)
    {
        if (tmp.width > 0.00000000 && tmp.height > 0.00000000 && (tmp.type == 'r' || tmp.type == 'R'))
            put_shapes_on_canvas(config, buff, &tmp);
        else
            return (false);
    }
    if (ret_scanf != -1)
        return (false);
    return (true);
}

static void paint(char *canvas, t_config *config)
{
    int i;
    i = 0;
    while (i < config->height)
    {
        write (1, canvas + (i * config->width), config->width);
        write (1, "\n", 1);
        i++;
    }
}

int main(int argc, char *argv[])
{
    char    *canvas;
    FILE *file;
    t_config    config;

    config.width = 0;
    config.height = 0;
    config.background = 0;
    if (argc != 2)
        return (str_err(ERR_ARG, 1));
    if (!(file = fopen(argv[1], "r")))
        return (clear_all(file, NULL) && str_err(ERR_OPE, 1));
    if (!(canvas = create_canvas(file, &config)))
        return (clear_all(file, NULL) && str_err(ERR_OPE, 1));
    if (!do_shapes(file, &config, canvas))
        return (clear_all(file, canvas) && str_err(ERR_OPE, 1));
    paint(canvas, &config);
    clear_all(file, canvas);
    return (0);
}
