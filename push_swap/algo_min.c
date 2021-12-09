/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:55:17 by ybentaye          #+#    #+#             */
/*   Updated: 2021/12/09 13:24:26 by ybentaye         ###   ########.fr       */
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
	while (temp->next)
	{
		if (temp->data < min)
		{
			min = temp->data;
			index = i;
		}
		temp = temp->next;
		i++;
	}
	while (index-- > 0)
		operations(lsta, lstb, 6);
	operations(lsta, lstb, 4);
}

void	push_min_all(t_stack **lsta, t_stack **lstb,int	size_stack)
{
	int	i;

	i = 0;
	while (i++ < size_stack)
		push_min(lsta, lstb);
		
}