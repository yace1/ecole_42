/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_util2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:28:31 by ybentaye          #+#    #+#             */
/*   Updated: 2021/12/20 12:43:21 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	up_down_move(t_stack	**lsta, t_stack	**lstb, int index)
{
	ft_printf("check ici\n");
	if (index == 0)
	{
		return ((void)(0));
	}
	else if (index <= (stack_size(*lsta) / 2))
	{
		while (index > 0)
		{
			operations(lsta, lstb, 6);
			index--;
		}
	}
	else
	{
		while (index < stack_size(*lsta))
		{
			operations(lsta, lstb, 9);
			index++;
		}
	}
}

int	is_sorted(t_stack *lst)
{
	int		i;
	t_stack	*temp;

	temp = lst;
	i = 1;
	while (temp)
	{
		if (temp->next != NULL)
		{
			if (temp->data > temp->next->data)
				return (0);
		}
		temp = temp->next;
		i++;
	}
	return (i);
}

int	max_index(t_stack *lst, int index)
{
	int		big;
	int		i;
	t_stack	*temp;

	temp = lst;
	big = 0;
	i = 0;
	while (index > 0)
	{
		temp = temp->next;
		index--;
	}
	index = 0;
	while (temp)
	{
		if (temp->data > big)
		{
			big = temp->data;
			index = i;
		}
		temp = temp->next;
		i++;
	}
	return (index);
}

void	double_operation(t_stack **lsta, t_stack **lstb, int op)
{
	if (op == 3)
	{
		sa_or_sb(lsta, 28);
		sa_or_sb(lstb, 0);
	}
	else if (op == 8)
	{
		ra_or_rb(lsta, 8);
		ra_or_rb(lsta, 0);
	}
	else if (op == 11)
	{
		rra_or_rrb(lsta, 11);
		rra_or_rrb(lstb, 0);
	}
}

void	op_radix(t_stack **lsta, t_stack **lstb, int t, int i)
{
	if ((t >> i) & 1)
		operations(lsta, lstb, 6);
	else
		operations(lsta, lstb, 4);
}
