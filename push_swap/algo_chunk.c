/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:37:14 by yacinebenta       #+#    #+#             */
/*   Updated: 2021/12/15 01:48:44 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *lst);
int	find_max(t_stack *lst);
void	push_chunk(t_stack **lsta, t_stack **lstb, t_chunk chunk);
int	is_in_chunk(t_stack **lst, t_chunk chunk);
int	first_push(int bot, int top, t_stack *lst);
void push_back_b(t_stack **lsta, t_stack **lstb);
void	up_down_b(t_stack	**lsta, t_stack	**lstb, int index);
int	find_max_index(t_stack *lst);

void	chunk_algo(t_stack **lsta, t_stack **lstb)
{
	t_chunk	chunk;

	chunk.min = find_min(*lsta);
	chunk.max = find_max(*lsta);
	chunk.size = (chunk.max - chunk.min) / 5;
	while (chunk.min < chunk.max && stack_size(*lsta))
	{
		while (is_in_chunk(lsta, chunk))
			push_chunk(lsta, lstb, chunk);
		chunk.min += chunk.size;
	}
	operations(lsta, lstb, 4);
	push_back_b(lsta, lstb);
}

void	push_chunk(t_stack **lsta, t_stack **lstb, t_chunk chunk)
{
	int	*top_hold;
	int	*bot_hold;
	int	i;
	t_stack	*temp;

	i = 0;
	top_hold = NULL;
	bot_hold = NULL;
	temp = (*lsta);
	while (temp)
	{
		if (temp->data < (chunk.min + chunk.size))
		{
			top_hold = malloc(sizeof(int));
			*top_hold = i;
			break ;
		}
		i++;
		temp = temp->next;
	}
	i = 0;
	temp = (*lsta);
	while (temp)
	{
		if (temp->data < (chunk.min + chunk.size))
		{
			bot_hold = malloc(sizeof(int));
			*bot_hold = i;
		}
		temp = temp->next;
		i++;
	}
	if (!top_hold && !bot_hold)
		return ;
	else if (!bot_hold)
		up_down(lsta, lstb, *top_hold);
	else if (!top_hold)
		up_down(lsta, lstb, *bot_hold);
	else
		up_down(lsta, lstb, first_push(*bot_hold, *top_hold, *lsta));
}

void push_back_b(t_stack **lsta, t_stack **lstb)
{
	int	max_ind;

	max_ind = 0; 
	while (stack_size(*lstb))
	{
		max_ind = find_max_index(*lstb);
		up_down_b(lsta, lstb, max_ind);
	}
}

int	is_in_chunk(t_stack **lst, t_chunk chunk)
{
	t_stack	*temp;
	int		res;

	res = 0;
	temp = (*lst);
	while (temp)
	{
		if (temp->data < (chunk.min + chunk.size))
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	first_push(int bot, int top, t_stack *lst)
{
	if (bot <= stack_size(lst) - top)
		return (bot);
	else
		return (top);
}

int	find_max_index(t_stack *lst)
{
	int		big;
	int		index;
	int		i;
	t_stack	*temp;

	temp = lst;
	big = 0;
	i = 0;
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

int	find_max(t_stack *lst)
{
	int		big;
	t_stack	*temp;

	temp = lst;
	big = 0;
	while (temp)
	{
		if (temp->data > big)
			big = temp->data;
		temp = temp->next;
	}
	return (big);
}

int	find_min(t_stack *lst)
{
	int		small;
	t_stack	*temp;

	temp = lst;
	small = temp->data;
	while (temp)
	{
		if (temp->data < small)
			small = temp->data;
		temp = temp->next;
	}
	return (small);
}

void	up_down_b(t_stack	**lsta, t_stack	**lstb, int index)
{
	if (index == 0)
	{
		operations(lsta, lstb, 5);
		return ((void)(0));
	}
	else if (index <= (stack_size(*lstb)/2))
	{
		while (index > 0)
		{
			operations(lsta, lstb, 7);
			index--;
		}
	}
	else
	{
		while (index < stack_size(*lstb))
		{
			operations(lsta, lstb, 10);
			index++;
		}
	}
	operations(lsta, lstb, 5);
}