/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:55:50 by yacinebenta       #+#    #+#             */
/*   Updated: 2021/12/16 22:55:53 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error_check(void)
{
	ft_putstr_fd("error\n", 1);
	exit (0);
}

t_stack	**parsing(t_stack **lst, char **argv, int argc)
{
	char	*str;

	if (argc < 2)
		exit_error();
	if (argc == 2)
	{
		str = argv[1];
		check_char(str);
		lst = parse_stck2(lst, ft_split(str, ' '),
				count_words(str, ' '));
		check_doublon(lst);
	}
	else
		lst = parse_stck(lst, argv, argc);
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
	ft_printf("nb: %d\n", nb);
}
