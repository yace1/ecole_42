/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:55:17 by ybentaye          #+#    #+#             */
/*   Updated: 2021/12/14 12:28:45 by ybentaye         ###   ########.fr       */
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
	// while (index-- > 0)
	// 	operations(lsta, lstb, 6);
	// operations(lsta, lstb, 4);
}

void	push_min_all(t_stack **lsta, t_stack **lstb, int size_stack)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	j = 0;
	while (i < size_stack / 2) // size_stack / 2
	{
		push_min(lsta, lstb);
		i++;
	}	
	ft_printf("ici\n");
	while (!is_sorted(*lsta))
	{
		k = max_index(*lsta, j); //recheck tjr le meme index faut trouver une solution
		up_down_move(lsta, lstb, k); //
		j++;
	}
}
// tester de trier apres avoir push

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

//check if we need to ra or rra
void	up_down(t_stack	**lsta, t_stack	**lstb, int index)
{
	if (index == 0)
	{
		operations(lsta, lstb, 4);
		return ((void)(0));
	}
	else if (index <= (stack_size(*lsta)/2))
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
	// if ((*lstb)->data < (*lstb)->next->data && stack_size(*lstb) >= 2)
	// 	operations(lsta, lstb, 3);
}

void	up_down_move(t_stack	**lsta, t_stack	**lstb, int index)
{
	ft_printf("check ici\n");
	if (index == 0)
	{
		return ((void)(0));
	}
	else if (index <= (stack_size(*lsta)/2))
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
	// if ((*lstb)->data < (*lstb)->next->data && stack_size(*lstb) >= 2)
	// 	operations(lsta, lstb, 3);
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
				i = 0;
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
