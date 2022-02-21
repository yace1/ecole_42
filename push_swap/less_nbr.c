/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 22:02:15 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/02/17 17:08:55 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	forth_nb(t_stack **lsta, t_stack **lstb);
void	fifth_nb(t_stack **lsta, t_stack **lstb);
int		case_34(t_stack **lsta, t_stack **lstb, int i);

void	less_than3(t_stack **lsta, t_stack **lstb)
{
	if ((*lsta)->data > (*lsta)->next->data)
		if ((*lsta)->next->next->data > (*lsta)->data)
			operations(lsta, lstb, 1);
	else if ((*lsta)->next->data > (*lsta)->next->next->data)
	{
		operations(lsta, lstb, 1);
		operations(lsta, lstb, 9);
	}
	else
		operations(lsta, lstb, 6);
	else if ((*lsta)->data > (*lsta)->next->next->data)
	{
		operations(lsta, lstb, 9);
	}	
	else if ((*lsta)->next->next->data > (*lsta)->data)
	{
		operations(lsta, lstb, 1);
		operations(lsta, lstb, 6);
	}
}

void	less_than5(t_stack **lsta, t_stack **lstb)
{
	int	i;

	i = 0;
	operations(lsta, lstb, 4);
	operations(lsta, lstb, 4);
	if (!is_sorted(*lsta))
		less_than3(lsta, lstb);
	forth_nb(lsta, lstb);
	fifth_nb(lsta, lstb);
}

void	forth_nb(t_stack **lsta, t_stack **lstb)
{
	if ((*lstb)->data < (*lsta)->data)
		operations(lsta, lstb, 5);
	else if ((*lstb)->data < (*lsta)->next->data)
	{
		operations(lsta, lstb, 5);
		operations(lsta, lstb, 1);
	}
	else if ((*lstb)->data < (*lsta)->next->next->data)
	{
		operations(lsta, lstb, 6);
		operations(lsta, lstb, 5);
		operations(lsta, lstb, 1);
		operations(lsta, lstb, 9);
	}
	else
	{
		operations(lsta, lstb, 5);
		operations(lsta, lstb, 6);
	}
}

void	fifth_nb(t_stack **lsta, t_stack **lstb)
{
	int		i;
	int		j;
	t_stack	*temp;

	i = 0;
	temp = *lsta;
	while (temp)
	{
		if (temp->data > (*lstb)->data)
			break ;
		temp = temp->next;
		i++;
	}
	j = i;
	if (!case_34(lsta, lstb, i))
		return ((void)(0));
	while (i > 0)
	{
		operations(lsta, lstb, 6);
		i--;
	}
	operations(lsta, lstb, 5);
	while (j-- > 0)
		operations(lsta, lstb, 9);
}

int	case_34(t_stack **lsta, t_stack **lstb, int i)
{
	if (i == 4)
	{
		operations(lsta, lstb, 5);
		operations(lsta, lstb, 6);
		return (0);
	}
	if (i == 3)
	{
		operations(lsta, lstb, 9);
		operations(lsta, lstb, 5);
		operations(lsta, lstb, 6);
		operations(lsta, lstb, 6);
		return (0);
	}
	return (1);
}
