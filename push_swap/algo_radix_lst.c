/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_radix_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:29:50 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/02/20 13:52:20 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_list(t_lst *lsta)
{
	int		*lst;
	int		i;

	lst = malloc(sizeof(int) * lsta->max_len);
	if (!lst)
		return (0);
	i = 0;
	while (i < lsta->len)
	{
		lst[i] = lsta->lst[i];
		i++;
	}
	return (lst);
}

void	stack_to_ind_lst(t_lst *lsta)
{
	int		i;
	int		j;
	int		*temp;
	int		*lst;

	temp = lsta->lst;
	lst = copy_list(lsta);
	i = 0;
	temp = sort_lst(lst, lsta->len);
	while (i < lsta->len)
	{
		j = 0;
		while (j < lsta->len)
		{
			if (lsta->lst[i] == temp[j])
			{
				lsta->lst[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(lst);
}

void	algo_radix_lst(t_lst *lsta, t_lst *lstb)
{
	int	i;
	int	max;
	int	max_bit;
	int	j;

	stack_to_ind_lst(lsta);
	max = lsta->max_len - 1;
	max_bit = 0;
	while (max >> max_bit)
		max_bit++;
	i = 0;
	while (i < max_bit)
	{
		j = -1;
		while (++j < lsta->max_len)
			op_radix_lst(lsta, lstb, lsta->lst[0], i);
		while (lstb->len)
			operations_lst(lsta, lstb, 5);
		i++;
	}
}

int	is_lst_sorted(t_lst *lst)
{
	int	i;

	i = 0;
	while (i < (lst->len) - 1)
	{
		if (lst->lst[i] > lst->lst[i + 1])
			return (0);
		i++;
	}
	return (1);
}
