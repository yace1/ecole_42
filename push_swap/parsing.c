/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:55:50 by yacinebenta       #+#    #+#             */
/*   Updated: 2021/12/10 17:06:35 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error_check(void)
{
	ft_putstr_fd("error\n", 1);
	exit (0);
}

t_stack	**parse_stck(t_stack **lst, char **argv, int argc)
{
	int		i;
	t_stack	*first;
	t_stack	*last;
	t_stack	*temp;

	first = malloc(sizeof(t_stack));
	if (!first)
		error_check();
	first->data = ft_atoi(argv[1]);
	first->next = NULL;
	last = first;
	i = 2;
	while (i < argc)
	{
		temp = malloc(sizeof(t_stack));
		if (!temp)
			error_check();
		temp->data = ft_atoi(argv[i]);
		temp->next = NULL;
		last->next = temp;
		last = temp;
		i++;
	}
	*lst = first;
	return (lst);
}

t_stack	**parse_stck2(t_stack **lst, char **str, int size)
{
	int		i;
	t_stack	*first;
	t_stack	*last;
	t_stack	*temp;

	first = malloc(sizeof(t_stack));
	if (!first)
		error_check();
	first->data = ft_atoi(str[0]);
	first->next = NULL;
	last = first;
	i = 1;
	while (i < size)
	{
		temp = malloc(sizeof(t_stack));
		if (!temp)
			error_check();
		temp->data = ft_atoi(str[i]);
		temp->next = NULL;
		last->next = temp;
		last = temp;
		i++;
	}
	*lst = first;
	return (lst);
}

/* if using array

	argv = (void *)argv;
	int	*list_a;
	int	*list_b;
	int	i;

	i = 0;
	list_a = malloc(sizeof(int) * (argc));
	list_b = malloc(sizeof(int) * (argc));
	while (i < argc - 1)
	{
		list_a[i] = ft_atoi(argv[i + 1]);
		printf("%d\n",list_a[i]);
		i++;
	}
*/