/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:55:17 by ybentaye          #+#    #+#             */
/*   Updated: 2021/12/20 12:30:30 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min(t_stack **lsta, t_stack **lstb)
{
	t_stack	*temp;
	int		min;
	int		i;
	int		index;

	i = 0;
	index = 0;
	temp = (*lsta);
	min = temp->data;
	while (stack_size(temp))
	{
		if (temp->data < min)
		{
			min = temp->data;
			index = i;
		}
		temp = temp->next;
		i++;
	}
	up_down(lsta, lstb, index);
}

void	push_min_all(t_stack **lsta, t_stack **lstb, int size_stack)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	j = 0;
	while (i < size_stack / 2)
	{
		push_min(lsta, lstb);
		i++;
	}	
	ft_printf("ici\n");
	while (!is_sorted(*lsta))
	{
		k = max_index(*lsta, j);
		up_down_move(lsta, lstb, k);
		j++;
	}
}

void	push_all_back(t_stack **lsta, t_stack **lstb)
{
	while (stack_size(*lstb))
	{
		operations(lsta, lstb, 5);
	}
}

void	algo_min(t_stack **lsta, t_stack **lstb)
{
	int	i;

	i = stack_size(*lsta);
	push_min_all(lsta, lstb, i);
	push_all_back(lsta, lstb);
}

void	up_down(t_stack	**lsta, t_stack	**lstb, int index)
{
	if (index == 0)
	{
		operations(lsta, lstb, 4);
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
	operations(lsta, lstb, 4);
}
