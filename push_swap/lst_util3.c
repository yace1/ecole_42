/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_util3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:47:07 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/02/20 13:51:36 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_operation_lst(t_lst *lsta, t_lst *lstb, int op)
{
	if (op == 3)
	{
		sa_or_sb_lst(lsta, 28);
		sa_or_sb_lst(lstb, 0);
	}
	else if (op == 8)
	{
		ra_or_rb_lst(lsta, 8);
		ra_or_rb_lst(lsta, 0);
	}
	else if (op == 11)
	{
		rra_or_rrb_lst(lsta, 11);
		rra_or_rrb_lst(lstb, 0);
	}
}

int	*update_lst_b(t_lst *list_a, t_lst *list_b, int *cp_b)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	cp_b[0] = list_a->lst[0];
	while (i < list_b->len)
	{
		cp_b[j] = list_b->lst[i];
		j++;
		i++;
	}
	return (cp_b);
}

int	*update_lst_a(t_lst *list_a, int *cp_a)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < list_a->len)
	{
		cp_a[i] = list_a->lst[j];
		j++;
		i++;
	}
	return (cp_a);
}

void	op_radix_lst(t_lst *lsta, t_lst *lstb, int t, int i)
{
	if ((t >> i) & 1)
		operations_lst(lsta, lstb, 6);
	else
		operations_lst(lsta, lstb, 4);
}

void	check_dbl_lst(t_lst *list)
{
	int		i;
	int		j;
	int		*temp;

	i = 0;
	temp = list->lst;
	while (i < list->len)
	{
		j = 0;
		while (j < list->len)
		{
			if ((temp[i] == temp[j] && i != j) || temp[i] > 2147483647)
			{
				free(list->lst);
				free(list);
				exit_error();
			}
			j++;
		}
		i++;
	}
}
