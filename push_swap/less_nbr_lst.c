/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_nbr_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:25:57 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/02/20 13:52:06 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_lst_sorted(t_lst *lst);
int		case_34_lst(t_lst *lsta, t_lst *lstb, int i);
void	fifth_nb_lst(t_lst *lsta, t_lst *lstb);
void	forth_nb_lst(t_lst *lsta, t_lst *lstb);

void	less_than3_lst(t_lst *lsta, t_lst *lstb)
{
	if (lsta->lst[0] > lsta->lst[1])
		if (lsta->lst[2] > lsta->lst[0])
			operations_lst(lsta, lstb, 1);
	else if (lsta->lst[1] > lsta->lst[2])
	{
		operations_lst(lsta, lstb, 1);
		operations_lst(lsta, lstb, 9);
	}
	else
		operations_lst(lsta, lstb, 6);
	else if (lsta->lst[0] > lsta->lst[2])
	{
		operations_lst(lsta, lstb, 9);
	}	
	else if (lsta->lst[2] > lsta->lst[0])
	{
		operations_lst(lsta, lstb, 1);
		operations_lst(lsta, lstb, 6);
	}
}

void	less_than5_lst(t_lst *lsta, t_lst *lstb)
{
	int	i;

	i = 0;
	operations_lst(lsta, lstb, 4);
	operations_lst(lsta, lstb, 4);
	if (!is_lst_sorted(lsta))
		less_than3_lst(lsta, lstb);
	forth_nb_lst(lsta, lstb);
	fifth_nb_lst(lsta, lstb);
}

void	forth_nb_lst(t_lst *lsta, t_lst *lstb)
{
	if (lstb->lst[0] < lsta->lst[0])
		operations_lst(lsta, lstb, 5);
	else if (lstb->lst[0] < lsta->lst[1])
	{
		operations_lst(lsta, lstb, 5);
		operations_lst(lsta, lstb, 1);
	}
	else if (lstb->lst[0] < lsta->lst[2])
	{
		operations_lst(lsta, lstb, 6);
		operations_lst(lsta, lstb, 5);
		operations_lst(lsta, lstb, 1);
		operations_lst(lsta, lstb, 9);
	}
	else
	{
		operations_lst(lsta, lstb, 5);
		operations_lst(lsta, lstb, 6);
	}
}

void	fifth_nb_lst(t_lst *lsta, t_lst *lstb)
{
	int		i;
	int		j;

	i = 0;
	while (i < lsta->len)
	{
		if (lsta->lst[i] > lstb->lst[0])
			break ;
		i++;
	}
	j = i;
	if (!case_34_lst(lsta, lstb, i))
		return ((void)(0));
	while (i > 0)
	{
		operations_lst(lsta, lstb, 6);
		i--;
	}
	operations_lst(lsta, lstb, 5);
	while (j-- > 0)
		operations_lst(lsta, lstb, 9);
}

int	case_34_lst(t_lst *lsta, t_lst *lstb, int i)
{
	if (i == 4)
	{
		operations_lst(lsta, lstb, 5);
		operations_lst(lsta, lstb, 6);
		return (0);
	}
	if (i == 3)
	{
		operations_lst(lsta, lstb, 9);
		operations_lst(lsta, lstb, 5);
		operations_lst(lsta, lstb, 6);
		operations_lst(lsta, lstb, 6);
		return (0);
	}
	return (1);
}
