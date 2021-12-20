/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:14:20 by ybentaye          #+#    #+#             */
/*   Updated: 2021/12/20 12:25:48 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	**lsta;
	t_stack	**lstb;

	lsta = malloc(sizeof(t_stack *));
	if (!lsta)
		exit_error();
	lsta = parsing(lsta, argv, argc);
	lstb = malloc(sizeof(t_stack *));
	if (!lstb)
		exit_error();
	choose_algo(lsta, lstb);
	//print_stack(lsta);
	free_stack(lsta);
	free_stack(lstb);
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
		ft_printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
	ft_printf("%d\n", ptr->data);
}
