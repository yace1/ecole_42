#include "philo.h"

void* action(void *arg)
{
	t_phil	philo;
	int		prev;
	int		next;
	int		tm_eat;
	int		tm_sleep;
	int		tm_die;

	philo = *(t_phil *)arg;
	printf("start philo: %d\n", philo.index);
	tm_eat = philo.tm_eat;
	tm_sleep = philo.tm_sleep;
	tm_die = philo.tm_die;
	if (philo.index == 0)
	{
		prev = philo.nb - 1;
		next = 1;
	}
	else if (philo.index == philo.nb - 1)
	{
		prev = philo.nb - 2;
		next = 0;
	}
	else
	{
		prev = philo.index - 1;
		next = philo.index + 1;
	}
	while (--philo.tm_die > -1)
	{
		philo.tm_eat = tm_eat;
		philo.tm_eat = tm_sleep;
		if (philo.fork == 0
			&& philo.lst[next].fork == 0)
		{
			pthread_mutex_lock(philo.mut);
			philo.fork = 1;
			philo.lst[next].fork = 1; 
			printf(" %d has taken a fork\n", philo.index);
			printf(" %d is eating\n", philo.index);
			while (--philo.tm_eat > -1)
				sleep(1);
			philo.fork = 0;
			philo.lst[next].fork = 0;
			philo.tm_die = tm_die;
			pthread_mutex_unlock(philo.mut);
			printf(" %d is sleeping\n", philo.index);
			while (--philo.tm_sleep > -1)
				sleep(1);
			printf(" %d is thinking\n", philo.index);
		}
		//printf(" %d can't take the fork\n", philo.index);
		sleep(1);
	}
	printf(" %d died\n", philo.index);
	exit (0); //should free lst and phil
    return ((void *)0);
}

int main(int argc, char* argv[])
{
    int				nb_tm_eat;
    pthread_t		*phil;
    int        		i;
    t_phil      	*lst;
	int				*ind;
	pthread_mutex_t	mut;

    nb_tm_eat = 0;
    if (argc < 5 || argc > 6)
        return (1);
    if (argc == 6)
        nb_tm_eat = ft_atoi(argv[5]);
    phil = malloc(sizeof(pthread_t *) * ft_atoi(argv[1]));
	if (!phil)
		return (0);
    lst = malloc(sizeof(t_phil) * ft_atoi(argv[1]));
	if (!lst)
		return (0);
	pthread_mutex_init(&mut, NULL);
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
		lst[i].mut = &mut;
    }
    i = -1;
    while (++i < ft_atoi(argv[1]))
    {
		ind = malloc(sizeof(int));
        pthread_create(&phil[i], NULL, &action, (void *)&(lst[i]));
    }
    i = -1;
    while (++i < ft_atoi(argv[1]))
    {
        pthread_join(phil[i], NULL);
    }
	pthread_mutex_destroy(&mut);
    return (0);
}