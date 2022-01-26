/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 23:08:45 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/01/26 15:53:19 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	pthread_t		*phil;
	t_phil			*lst;
	pthread_mutex_t	mut;
	int				nb_eat;

	phil = malloc(sizeof(pthread_t *) * ft_atoi(argv[1]));
	if (!phil)
		return (0);
	lst = malloc(sizeof(t_phil) * ft_atoi(argv[1]));
	if (!lst)
		return (0);
	nb_eat = check_arg(argc, argv);
	pthread_mutex_init(&mut, NULL);
	fill_lst(lst, argv, &mut, nb_eat);
	thread_handle(argv, lst, phil);
	pthread_mutex_destroy(&mut);
	return (0);
}

void	fill_lst(t_phil *lst, char *argv[], pthread_mutex_t *mut, int nb)
{
	int				i;
	struct timeval	tm_curr;
	int				start;

	gettimeofday(&tm_curr, NULL);
	start = tm_curr.tv_usec;
	i = -1;
	while (++i < ft_atoi(argv[1]))
	{
		lst[i].index = i;
		lst[i].tm_die = ft_atoi(argv[2]);
		lst[i].tm_eat = ft_atoi(argv[3]);
		lst[i].tm_sleep = ft_atoi(argv[4]);
		lst[i].fork = 0;
		lst[i].nb = ft_atoi(argv[1]);
		lst[i].lst = lst;
		lst[i].mut = mut;
		lst[i].tm_start = start;
		lst[i].tm_curr = &tm_curr;
		lst[i].nb_eat = nb;
	}
}

int	get_tm(struct timeval *curr)
{
	gettimeofday(curr, NULL);
	return (curr->tv_usec);
}

int	check_arg(int argc, char *argv[])
{
	int				nb_tm_eat;

	nb_tm_eat = -1;
	if (argc < 5 || argc > 6)
		exit_error();
	if (argc == 6)
	{
		nb_tm_eat = ft_atoi(argv[5]);
		printf("nb of meal: %d\n", nb_tm_eat);
		if (nb_tm_eat < 1)
			exit_error();
		return (nb_tm_eat);
	}
	else
		nb_tm_eat = -1;
	return (nb_tm_eat);
}

void	thread_handle(char *argv[], t_phil *lst, pthread_t *phil)
{
	int	i;

	i = -1;
	while (++i < ft_atoi(argv[1]))
	{
		pthread_create(&phil[i], NULL, &action, (void *)&(lst[i]));
	}
	i = -1;
	while (++i < ft_atoi(argv[1]))
	{
		pthread_join(phil[i], NULL);
	}
}
