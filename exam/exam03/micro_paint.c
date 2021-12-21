/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:02:31 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/21 15:02:33 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define ERR_ARG "Error: argument\n"
#define ERR_OPF "Error: Operation file corrupted\n"

typedef struct  s_canvas
{
    int width;
    int height;
    char background;
}   t_canvas;

typedef struct  s_shape
{
    char type; 
    int x;
    int y;
    int width;
    int height;
    char rectangle;
}   t_shape;


int create_canvas(FILE *file, t_canvas *canva)
{
    char *result = NULL;
    int ret_scanf;

    ret_scanf = fscanf(file,"%d %d %c", &canva->width, &canva->height, &canva->background);
    if (ret_scanf == 3 && 0 < canva->width && canva->width <= 300 || 0 < canva->height && canva->height <= 300)
    {
        result = (char *)calloc(canva->width * canva->height + 1, sizeof(char));
        result = memset (result, canva->background, canva->width * canva->height);
    }
    return (result);
}

int create_shapes(FILE *file, t_canvas *canva)
{
    char *result = NULL;
    
    while (ret_scanf = fscanf(file,"%d %d %c", &canva->width, &canva->height, &canva->background))
}

int main(int argc, char *argv[])
{
    int ret;
    FILE *file;
    char *canvas;
    t_canvas canvas = {0};

    ret = 1;
    if (argc != 2)
    {
        ft_putstr(ERR_ARG);
    }
    else if (!(file = fopen(argv[1], "r")))
    {
        ft_putstr(ERR_OPF);
    }
    else if (!(canvas = create_canvas(file, canvas)))
    {
        ft_putstr(ERR_OPF);
    }
    else if (!(shapes = create_shapes()))
    {
        ft_putstr(ERR_OPF);
    }
    else
    {
        paint(canvas, &config);
        ret = 0;
    }
    if (file)
        fclose (file);

    return (ret);
}



