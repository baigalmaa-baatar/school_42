/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 20:57:37 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/28 20:57:38 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//./philo 4 100 200 300 test it 40 times.
//./philo 4 410 200 200

int str_err(char *str, int ret)
{
    write(1, str, ft_strlen(str));
    return (ret);
}

// #define UNUSED(x) (void)(x)
void display_stat(pthread_mutex_t *lock, unsigned long long pId, char *str)
{
	pthread_mutex_lock(lock);
	ft_putnbr_fd(getTime(), 1);
	write(1," ", 1);
	ft_putnbr_fd(pId, 1);
	write(1, str, ft_strlen(str));
	pthread_mutex_unlock(lock);
}

void    *routine(void *arg)
{
	int ateCntr;
	pthread_mutex_t *leftFork;
    pthread_mutex_t *rightFork;
	t_philo *philos;

	philos = (t_philo *)arg;
	ateCntr = 0;
	// printf("Thread has created!!!: %d\n", philos->pId);
	
    while (1)
    {
		if (!(*philos->running))
        {
            // printf("before break %llu\n", philos->pId);
			break;
        }
		// printf("Why it is not breaking in previuos line?? %llu\n", philos->pId);
        
		leftFork = &philos->forks[philos->pId];
        rightFork = &philos->forks[(philos->pId + 1) % philos->philoNum];
		// printf("aaaaaaaa %llu enen deer neg yum hevleed uz dee\n", philos->pId);

        // if(philos->pId % 2)
		// {
		if (philos->pId % 2)
		{
			usleep((float)philos->timeToDie * 0.9 + 1);
		}
		pthread_mutex_lock(leftFork);
        pthread_mutex_lock(rightFork);
		if (!(*philos->running))
		{
        	pthread_mutex_unlock(leftFork);
        	pthread_mutex_unlock(rightFork);
			break;
		}
		display_stat(philos->message, philos->pId," has taken a fork\n");
        // printf("%llu %llu has taken a fork\n", getTime(), philos->pId);
		// }
		// else
		// {
		// 	pthread_mutex_lock(rightFork);
		// 	pthread_mutex_lock(leftFork);
		// 	if (!(*philos->running))
		// 	{
        // 		pthread_mutex_unlock(rightFork);
		// 		pthread_mutex_unlock(leftFork);
		// 		break;
		// 	}
		// 	display_stat(philos->message, philos->pId + 1," has taken a fork\n");
        // 	// printf("%llu %llu has taken a fork\n", getTime(), philos->pId);
		// }
		// printf("aaaaaaaa %llu enen deer neg yum hevleed uz dee\n", philos->pId);
		if (!(*philos->running))
			{
        		pthread_mutex_unlock(rightFork);
				pthread_mutex_unlock(leftFork);
				break;
			}
		if (ateCntr == (int)philos->mustEatNbr)
			{
        		pthread_mutex_unlock(rightFork);
				pthread_mutex_unlock(leftFork);
				break;
			}
		else
			ateCntr++;
		// printf("inputval time to eat : %llu\n", philos->timeToEat);
		philos->ltaArr[philos->pId] = getTime();
		display_stat(philos->message, philos->pId + 1," is eating\n");
        usleep(philos->timeToEat * 1000);
        pthread_mutex_unlock(leftFork);
        pthread_mutex_unlock(rightFork);
		if (!(*philos->running))
			break;
		display_stat(philos->message, philos->pId + 1," is sleeping\n");
		// printf("%llu %llu is sleeping\n", getTime(), philos->pId);
        usleep(philos->timeToSleep * 1000);
		// preciseSleep(philos->timeToSleep);
		if (!(*philos->running))
			break;
		display_stat(philos->message, philos->pId + 1," is thinking\n");
        // printf("%llu %llu is thinking\n", getTime(), philos->pId);
    }
    return (NULL);
}

bool	init_philos(t_philo *philos, int philoNum)
{
	philos->philoNum = philoNum;
	philos->pId = 0;
	return (true);
}

int small_thread(t_philo *philos, unsigned long long deltaLTA)
{
	unsigned int i;
    i = 0;
    while(i < philos->philoNum)
    {
	    // printf("Creating the small thread pId : %u\n", i);
		deltaLTA = getTime() - philos->ltaArr[i];
		// printf("timeToDie: %llu\n", philos->timeToDie);
		// printf("timeToEat: %llu\n", philos->timeToEat);
       	if (deltaLTA >= philos->timeToDie)// || philos->timeToEat > philos->timeToDie)//|| philos->timeToDie < philos->timeToSleep)
		{
			display_stat(philos->message, philos->pId + 1," died\n");
			// printf("%llu %d died\n", getTime(), i);
			*(philos->running) = false;
			return (0);
		}
        // printf("NULL butsaasnii daraa\n");
		i++;
    }
    return (1);
}

void    *detectDeath(void *arg)
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
		// printf("enen deer neg yum hevleed uz dee\n");
	}
	return (NULL);
}

int main(int argc, char *argv[])
{
    unsigned int i;
    pthread_t   p_th[100];
	unsigned long long ltaArr[100];
	pthread_mutex_t forks[100];
	pthread_mutex_t message;
	t_philo philos[100];
	t_philo deathStr;
	pthread_t deathThread;
	bool running;
	unsigned long long inputVal[5];
	unsigned long long philoNbr;
	unsigned long long timeToDie;
	unsigned long long timeToEat;
	unsigned long long timeToSleep;
	unsigned long long mustEatNbr;

	if (argc < 5 || argc > 6)
		str_err(ERR_ARG, 1);
	// philoNbr = get_args(argv, &inputVal);
	philoNbr = get_args(argc, argv, inputVal);
	timeToDie = inputVal[1];
	timeToEat = inputVal[2];
	timeToSleep = inputVal[3];
	if (argc == 6)
		mustEatNbr = inputVal[4];
	else
		mustEatNbr = -1;
	// printf("Number of philo: %llu\n", philoNbr);
	// printf("Time to die : %llu\n", timeToDie);
	// printf("Time to eat : %llu\n", timeToEat);
	// printf("Time to sleep : %llu\n", timeToSleep);
	if (!philoNbr)
		str_err(ERR_ARG, 1);
	running = true;
	i = 0;
	while (i < philoNbr)
	{
		ltaArr[i] = getTime();
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&message, NULL);
	// pthread_mutex_init(&deathlock, NULL);
    i = 0;
    while(i < philoNbr)
    {
		philos[i].philoNum = philoNbr;
		philos[i].forks = &forks[0];
		philos[i].ltaArr = &ltaArr[0];
		philos[i].running = &running;
		philos[i].timeToDie = timeToDie;
		philos[i].timeToEat = timeToEat;
		philos[i].timeToSleep = timeToSleep;
		philos[i].mustEatNbr = mustEatNbr;
		philos[i].message = &message;
		philos[i].pId = i;
        if (pthread_create(&p_th[i], NULL, &routine, &philos[i]) != 0)
        {
            // printf("checking it is here %u\n", i);
            return(str_err(ERR_CRT, 1));
        }
		i++;
		// usleep(10000);
    }
	deathStr.philoNum = philoNbr;
    deathStr.ltaArr = &ltaArr[0];
	deathStr.running = &running;
	deathStr.timeToDie = timeToDie;
	deathStr.timeToEat = timeToEat;
	deathStr.timeToSleep = timeToSleep;
	deathStr.message = &message;
	// printf("timeToDie : %llu\n", deathStr.timeToDie);
	// printf("timeToEat : %llu\n", deathStr.timeToEat);
	// printf("timeToSleep : %llu\n", deathStr.timeToSleep);

	if (pthread_create(&deathThread, NULL, &detectDeath, &deathStr) != 0)
        return (str_err(ERR_CRT, 1));
	i = 0;
    while(i < philoNbr)
    {
        if(pthread_join(p_th[i], NULL) != 0)
            return (str_err(ERR_JOIN, 1));
        i += 1;
    }
    if(pthread_join(deathThread, NULL) != 0)
            return (str_err(ERR_JOIN, 1));
    // i = 0;
    // while(i < 2)
    // {
    //     if (pthread_detach(p[i]) != 0)
    //         str_err(ERR_DET, 1);
    //     i += 2;
    // }
    i = 0;
    while (i < philoNbr)
    {
        pthread_mutex_destroy(&forks[i]);
        i++;
    }
	// free(philos);
    return (0);
}
