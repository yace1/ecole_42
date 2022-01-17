#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include "libft/libft.h"

typedef struct s_phil
{
	int					tm_die;
	int 				tm_sleep;
	int					tm_eat;
	int					fork;
	int					index;
	int					nb;
	pthread_mutex_t	*mut;
	struct s_phil	*lst;
}	t_phil;


#endif