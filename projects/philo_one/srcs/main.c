/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:59:00 by bbaatar           #+#    #+#             */
/*   Updated: 2022/01/05 22:59:43 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	str_err(char *str, int ret)
{
	write(1, str, ft_strlen(str));
	return (ret);
}

int	init(t_inputVal *inputVal, unsigned long long ltaArr[],
		pthread_mutex_t forks[], pthread_mutex_t *message)
{
	unsigned int	i;

	i = 0;
	while (i < inputVal->philoNbr)
	{
		ltaArr[i] = get_time();
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	pthread_mutex_init(message, NULL);
	return (1);
}

int	display_stat(t_philo *philos, char *str, unsigned long long timeToDo)
{
	if (!*philos->running)
		return (0);
	pthread_mutex_lock(philos->message);
	ft_putnbr_fd(get_time(), 1);
	write (1," ", 1);
	ft_putnbr_fd(philos->pId + 1, 1);
	write(1, str, ft_strlen(str));
	pthread_mutex_unlock(philos->message);
	if (timeToDo)
		usleep(timeToDo * 1000);
	return (1);
}

int	checkPhiloDied(bool running, pthread_mutex_t *left_fork, pthread_mutex_t *right_fork)
{
	if (!running)
	{
		pthread_mutex_unlock(left_fork);
		pthread_mutex_unlock(right_fork);
		return (0);
	}
	return (1);
}

int	checkAteEnough(int *ateCntr, int mustEatNbr, pthread_mutex_t *left_fork, 
		pthread_mutex_t *right_fork)
{
	if (*ateCntr == mustEatNbr)
	{
		pthread_mutex_unlock(right_fork);
		pthread_mutex_unlock(left_fork);
		return (0);
	}
	else
		(*ateCntr)++;
	return (1);
}

void	takeForks(t_philo *philos, pthread_mutex_t *left, pthread_mutex_t *right)
{
	pthread_mutex_lock(left);
	pthread_mutex_lock(right);
	display_stat(philos, " has taken a fork\n", 0);
}

void	releaseForks(pthread_mutex_t *left, pthread_mutex_t *right)
{
	pthread_mutex_unlock(left);
	pthread_mutex_unlock(right);
}

void	eat(t_philo *philos)
{
	philos->ltaArr[philos->pId] = get_time();
	display_stat(philos, " is eating\n", philos->inputVal.timeToEat);
}

void	*routine(void *arg)
{
	int	ateCntr;

	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	t_philo *philos;

	philos = (t_philo *)arg;
	ateCntr = 0;
	left_fork = &philos->forks[philos->pId];
	right_fork = &philos->forks[(philos->pId + 1) % philos->inputVal.philoNbr];
	usleep((philos->pId % 2) * 15000);
	while (1)
	{
		if (!(*philos->running))
			break;
		takeForks(philos, left_fork, right_fork);
		//if (!checkPhiloDied(*(philos->running), left_fork, right_fork))
		//	break;
		if (!checkAteEnough(&ateCntr, (int)philos->inputVal.mustEatNbr, left_fork, right_fork))
			break;
		eat(philos);
		releaseForks(left_fork, right_fork);
		display_stat(philos, " is sleeping\n", philos->inputVal.timeToSleep);
		display_stat(philos, " is thinking\n", 0);
	}
	return (NULL);
}

int	small_thread(t_philo *philos, unsigned long long deltaLTA)
{
	unsigned int	i;
	
	i = 0;
	while(i < philos->inputVal.philoNbr)
	{
		deltaLTA = get_time() - philos->ltaArr[i];
		if (deltaLTA >= philos->inputVal.timeToDie)
		{
			philos->pId = i;
			display_stat(philos, " died\n", 0);
			*(philos->running) = false;
			return (0);
		}
		i++;
	}
	return (1);
}

void	*detectDeath(void *arg)
{
	unsigned long long deltaLTA;
	t_philo *philos;

	philos = (t_philo *)arg;
	deltaLTA = 0;
	while (1)
	{
		if (!small_thread(philos, deltaLTA))
			return (NULL);
		usleep(5000);
	}
	return (NULL);
}

int	joinThr(t_inputVal inputVal, pthread_t *p_th, pthread_t *deathThread)
{
	unsigned int i;

	i = 0;
	while(i < inputVal.philoNbr)
	{
		if(pthread_join(p_th[i], NULL) != 0)
			return (str_err(ERR_JOIN, 4));
		i++;
	}
	if(pthread_join(*deathThread, NULL) != 0)
		return (str_err(ERR_JOIN, 4));
	return (0);
}

pthread_t	create_sub_thread(t_inputVal inputVal, unsigned long long ltaArr[], bool running, pthread_mutex_t *message)
{
	pthread_t deathThread;
	t_philo deathStr;

	deathStr.ltaArr = &ltaArr[0];
	deathStr.running = &running;
	deathStr.message = message;
	deathStr.inputVal = inputVal;
	if (pthread_create(&deathThread, NULL, &detectDeath, &deathStr) != 0)
		str_err(ERR_CRT, 3);
	return (deathThread);
}

int	createThrds(t_inputVal inputVal, unsigned long long ltaArr[], pthread_mutex_t forks[], pthread_mutex_t *message)
{
	unsigned int i;
	pthread_t   p_th[2000];
	pthread_t deathThread;
	t_philo philos[2000];
	bool running;

	running = true;
	i = 0;
	while(i < inputVal.philoNbr)
	{
		philos[i].inputVal = inputVal;
		philos[i].forks = &forks[0];
		philos[i].ltaArr = &ltaArr[0];
		philos[i].running = &running;
		philos[i].message = message;
		philos[i].pId = i;
		if (pthread_create(&p_th[i], NULL, &routine, &philos[i]) != 0)
			return(str_err(ERR_CRT, 3));
		i++;
	}
	deathThread = create_sub_thread(inputVal, ltaArr, running, message);
	if (joinThr(inputVal, p_th, &deathThread))
		return (str_err(ERR_JOIN, 4));
	return (0);
}

int	clean(t_inputVal *inputVal, pthread_mutex_t forks[], pthread_mutex_t *message)
{
	unsigned int i;

	i = 0;
	while (i < inputVal->philoNbr)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	pthread_mutex_destroy(message);
	return (1);
}

int main(int argc, char *argv[])
{
	t_inputVal	inputVal;
	unsigned long long ltaArr[2000];
	pthread_mutex_t forks[2000];
	pthread_mutex_t message;

	if (!(get_args(argc, argv, &inputVal)))
		return (str_err(ERR_ARG, 1));
	if (!(init(&inputVal, ltaArr, forks, &message)))
		return (str_err(ERR_INIT, 1));
	if(createThrds(inputVal, ltaArr, forks, &message))
		return (str_err(ERR_CRT, 1));
	clean(&inputVal, forks, &message);
	return (0);
}
