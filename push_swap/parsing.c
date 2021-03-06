/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:55:50 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/02/20 15:37:57 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_check(void)
{
	ft_putstr_fd("error\n", 1);
	exit (0);
}

t_stack	**parsing(t_stack **lst, char **argv, int argc)
{
	char	*str;

	if (argc < 2)
		exit (0);
	if (argc == 2)
	{
		str = argv[1];
		lst = parse_stck2(lst, ft_split(str, ' '),
				count_words(str, ' '));
		check_doublon(lst);
	}
	else
	{
		lst = parse_stck(lst, argv, argc);
		check_doublon(lst);
	}
	return (lst);
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
	first->data = ft_atol(argv[1]);
	first->next = NULL;
	last = first;
	i = 2;
	while (i < argc)
	{
		temp = malloc(sizeof(t_stack));
		if (!temp)
			error_check();
		temp->data = ft_atol(argv[i]);
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
	first->data = ft_atol(str[0]);
	first->next = NULL;
	last = first;
	i = 1;
	while (i < size)
	{
		temp = malloc(sizeof(t_stack));
		if (!temp)
			error_check();
		temp->data = ft_atol(str[i]);
		temp->next = NULL;
		last->next = temp;
		last = temp;
		i++;
	}
	*lst = first;
	return (lst);
}

void	choose_algo(t_stack **lsta, t_stack **lstb)
{
	int	nb;

	nb = stack_size(*lsta);
	if (is_sorted(*lsta))
		return ((void)(0));
	else if (nb == 0)
		error_check();
	else if (nb == 1)
		exit (0);
	else if (nb == 3)
		less_than3(lsta, lstb);
	else if (nb == 5)
		less_than5(lsta, lstb);
	else
		algo_radix(lsta, lstb);
}
