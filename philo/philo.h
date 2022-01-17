#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include "libft/libft.h"

typedef struct s_phil
{
	double	tm_die;
	double 	tm_sleep;
	double	tm_eat;
	int		eat_state;
	int		index;
	struct s_phil	*lst;
}	t_phil;


#endif