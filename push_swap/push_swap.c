/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:14:20 by ybentaye          #+#    #+#             */
/*   Updated: 2021/12/13 22:21:02 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	**lsta;
	t_stack	**lstb;
	char	*lst;

	lsta = malloc(sizeof(t_stack *));
	if (!lsta)
		return (0);
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		lst = argv[1];
		lsta = parse_stck2(lsta, ft_split(lst, ' '),
				count_words(lst, ' '));
	}
	else
		lsta = parse_stck(lsta, argv, argc);
	lstb = malloc(sizeof(t_stack *));
	if (!lstb)
		return (0);
	algo_min(lsta, lstb);
	ft_printf("stack a\n");
	print_stack(lsta);
	// ft_printf("stack b\n");
	// print_stack(lstb);
}

void	print_stack(t_stack **stck)
{
	t_stack	*ptr;

	if (!stck)
		return ((void)(0));
	if (!*stck)
	{
		ft_printf("vide\n");
		return ((void)(0));
	}
	ptr = *stck;
	while (ptr->next)
	{
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
	printf("%d\n", ptr->data);
}


