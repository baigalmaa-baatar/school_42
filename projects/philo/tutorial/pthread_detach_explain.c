/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_detach_explain.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 20:41:29 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/28 20:41:57 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_thread.h"

#define _OPEN_SYS
#define _OPEN_THREADS
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void *thread(void *arg)
{
	char *ret;
	
	printf("thread() entered with argument '%s'\n", (char *)arg);
	if ((ret = (char*) malloc(20)) == NULL) {
		perror("malloc() error");
		exit(2);
	}
	strcpy(ret, "This is a test");
	pthread_exit(ret);
}

int	main(void)
{
	pthread_t th_id;
	void *ret;

	if (pthread_create(&th_id, NULL, thread, "thread 1") != 0) {
		perror("pthread_create() error");
		exit(1);
	}

	if (pthread_join(th_id, &ret) != 0) {
		perror("pthread_join() error");
		exit(3);
	}

	printf("thread exited with '%s'\n", (char *)ret);

	if (pthread_detach(th_id) != 0) {
		perror("pthread_detach() error");
		exit(4);
	}
	return (0);
}
