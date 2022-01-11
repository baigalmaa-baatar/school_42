/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 15:52:03 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/24 15:52:04 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ERR_ARG "Error: argument\n"
#define ERR_OPE "Error: Operation file corrupted\n"

typedef struct s_config
{
	int w;
	int	h;
	char background;
}	t_config;

typedef struct s_shape
{
	char type;
	float x;
	float y;
	float r;
	char c;
}	t_shape;

size_t	ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	str_err(char *str, int ret)
{
	write (1, str, ft_strlen(str));
	return (ret);
}

int	clean_and_free(FILE *file, char *str)
{
	fclose (file);
	if (str)
		free(str);
	return (1);
}

char *create_canvas(FILE *file, t_config *config)
{
	int ret_scanf;
	char *buff = NULL;

	ret_scanf = fscanf(file, "%d %d %c\n", &config->w, &config->h, &config->background);
	if (ret_scanf == 3 && config->w > 0 && config->w <= 300 && config->h <= 300 && config->h > 0)
	{
		buff = (char *)calloc(config->w * config->h + 1, 1);
		buff = memset(buff, config->background, config->w * config->h);
	}
	return (buff);
}

int	is_in_shape(float x, float y, t_shape *tmp)
{
	float e = 1.00000000;
	float dist = sqrtf(powf(x - tmp->x, 2.00000000) + powf(y - tmp->y, 2.00000000));

	if (dist <= tmp->r)
	{
		if (tmp->r - dist < e)
			return (2);
		return (1);
	}
	return (0);
}

void	create_shapes_on_canvas(t_shape *tmp, t_config *config, char *buff)
{
	int x;
	int y;
	int flag;

	y = 0;
	while (y < config->h)
	{
		x = 0;
		while (x < config->w)
		{
			flag = is_in_shape((float)x, (float)y, tmp);
			if ((flag == 2 && tmp->type == 'c') || (flag && tmp->type == 'C'))
				buff[y * config->w + x] = tmp->c;
			x++;
		}
		y++;
	}
}

bool do_shapes(FILE *file, t_config *config, char *canvas)
{
	int ret_scanf;
	t_shape tmp;
	//	c X Y RADIUS CHAR
	while((ret_scanf = fscanf(file, "%c %f %f %f %c\n", &tmp.type, &tmp.x, &tmp.y, &tmp.r, &tmp.c)) == 5)
	{
		if (tmp.r > 0.00000000 && (tmp.type == 'c' || tmp.type == 'C'))
		{
			create_shapes_on_canvas(&tmp, config, canvas);
		}
		else
			return (false);
	}
	if (ret_scanf != -1)
		return (false);
	return (true);
}

void	paint(t_config *config, char *canvas)
{
	int i;

	i = 0;
	while (i < config->h)
	{
		write(1, canvas + i * config->w, config->w);
		write (1, "\n", 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	char		*canvas;
	FILE		*file;
	t_config	config;

	if (argc != 2)
		return (str_err(ERR_ARG, 1));
	if (!(file = fopen(argv[1], "r")))
		return (str_err(ERR_OPE, 1), clean_and_free(file, NULL));
	if (!(canvas = create_canvas(file, &config)))
		return (str_err(ERR_OPE, 1), clean_and_free(file, NULL));
	if(!do_shapes(file, &config, canvas))
		return (str_err(ERR_OPE, 1), clean_and_free(file, canvas));
	
	paint(&config, canvas);
	clean_and_free(file, canvas);
	return(0);
}
