/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:37:14 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/02/17 15:20:34 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_min(t_stack *lst);
int		find_max(t_stack *lst);
int		first_push(int bot, int top, t_stack *lst);
int		find_max_index(t_stack *lst);

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
