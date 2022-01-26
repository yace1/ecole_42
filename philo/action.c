/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 23:08:41 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/01/26 16:07:52 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*action(void *arg)
{
	t_phil	philo;
	int		next;
	int		tm_eat;
	int		tm_sleep;
	int		tm_die;

	philo = *(t_phil *)arg;
	printf("start philo: %d\n", philo.index + 1);
	tm_eat = philo.tm_eat;
	tm_sleep = philo.tm_sleep;
	tm_die = philo.tm_die;
	next = who_is_next(philo);
	while (--philo.tm_die > -1)
	{
		philo.tm_eat = tm_eat;
		philo.tm_sleep = tm_sleep;
		check_fork(&philo, next, tm_die);
		usleep(10000);
	}
	printf("%d %d died\n", get_tm(philo.tm_curr), philo.index + 1);
	free_my_hommies(&philo);
	return ((void *)0);
}

void	sleepy(t_phil *phil)
{
	printf("%d %d is sleeping\n",
		get_tm(phil->tm_curr), phil->index + 1);
	while (--(phil->tm_sleep) > -1)
	{
		usleep(1000);
		(phil->tm_die)--;
		if ((phil->tm_die) < -1)
		{
			printf("%d %d died\n",
				get_tm(phil->tm_curr), phil->index + 1);
			free_my_hommies(phil);
		}
	}
}
//should usleep and reduce the time
//to die as well and check if time to die <= 0

void	check_fork(t_phil *phil, int next, int tm_die)
{
	if ((phil->fork) == 0
		&& (phil->lst[next].fork) == 0)
	{
		pthread_mutex_lock(phil->mut);
		phil->fork = 1;
		phil->lst[next].fork = 1;
		printf("%d %d has taken a fork\n",
			get_tm(phil->tm_curr), phil->index + 1);
		phil->nb_eat = eating(phil);
		phil->fork = 0;
		phil->lst[next].fork = 0;
		pthread_mutex_unlock(phil->mut);
		phil->tm_die = tm_die;
		sleepy(phil);
		printf("%d %d is thinking\n",
			get_tm(phil->tm_curr), phil->index + 1);
	}
}

int	who_is_next(t_phil philo)
{
	int	next;

	next = 0;
	if (philo.index == 0)
		next = 1;
	else if (philo.index == philo.nb - 1)
		next = 0;
	else
		next = philo.index + 1;
	return (next);
}

int	eating(t_phil *phil)
{
	printf("%d %d is eating\n",
		get_tm(phil->tm_curr), phil->index + 1);
	while (--(phil->tm_eat) > -1)
		usleep(1000);
	if (phil->nb_eat != -1)
	{
		printf("still have to eat: %d meal\n", phil->nb_eat);
		phil->nb_eat--;
		if (phil->nb_eat != 0)
			return (phil->nb_eat);
	}
	if (phil->nb_eat == 0)
	{
		printf("%d %d has eaten all his meal\n",
			get_tm(phil->tm_curr), phil->index + 1);
		free_my_hommies(phil);
	}
	return (phil->nb_eat);
}
