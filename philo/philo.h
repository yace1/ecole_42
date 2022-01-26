/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 23:08:47 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/01/26 16:03:21 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include "libft/libft.h"

typedef struct s_phil
{
	int				tm_die;
	int				tm_sleep;
	int				tm_eat;
	int				fork;
	int				index;
	int				nb;
	int				nb_eat;
	int				tm_start;
	struct timeval	*tm_curr;
	pthread_mutex_t	*mut;
	struct s_phil	*lst;
}	t_phil;

void	fill_lst(t_phil *lst, char *argv[], pthread_mutex_t *mut, int nb);
int		get_tm(struct timeval *curr);
int		check_arg(int argc, char *argv[]);
void	*action(void *arg);
void	thread_handle(char *argv[], t_phil *lst, pthread_t *phil);
void	exit_error(void);
void	sleepy(t_phil *phil);
void	check_fork(t_phil *phil, int next, int tm_die);
int		who_is_next(t_phil philo);
void	free_my_hommies(t_phil *phil);
int		eating(t_phil *phil);

#endif