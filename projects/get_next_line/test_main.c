/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 13:51:11 by bbaatar           #+#    #+#             */
/*   Updated: 2021/06/03 13:51:15 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int   main()
{
  char  *line;
  int   fd3;

  fd3 = open("file2", O_RDONLY);

  get_next_line(fd3, &line);
  printf("current buff is : %s\n", line);
  
  get_next_line(fd3, &line);
  printf("current buff is : %s\n", line);
  
  get_next_line(fd3, &line);
  printf("current buff is : %s\n", line);

  get_next_line(fd3, &line);
  printf("current buff is : %s\n", line);

   get_next_line(fd3, &line);
  printf("current buff is : %s\n", line);

  return (0);
}
