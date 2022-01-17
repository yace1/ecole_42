#include "philo.h"

void* action(void *arg)
{
	t_phil lst;

	lst = *(t_phil *)arg;
	printf("in the thread: %d\n", lst.index);
    return ((void *)0);
}

int main(int argc, char* argv[])
{
    int         nb_tm_eat;
    pthread_t   *phil;
    int         i;
    t_phil      *lst;
	int			*ind;

    nb_tm_eat = 0;
    if (argc < 5)
        return (1);
    if (argc == 6)
        nb_tm_eat = ft_atoi(argv[5]);
    phil = malloc(sizeof(pthread_t *) * ft_atoi(argv[1]));
	if (!phil)
		return (0);
    lst = malloc(sizeof(t_phil) * ft_atoi(argv[1]));
	if (!lst)
		return (0);
	    i = -1;
    while (++i < ft_atoi(argv[1]))
    {
        lst[i].index = i;
		lst[i].lst = lst;
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


    return (0);
}