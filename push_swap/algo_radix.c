/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:58:16 by ybentaye          #+#    #+#             */
/*   Updated: 2022/02/20 13:50:44 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*swap_elem(int *lst, int ind1, int ind2);
int		*sort_lst(int *lst, int size);
int		*copy_stack(t_stack	**lsta);
void	swap(int *xp, int *yp);

void	algo_radix(t_stack **lsta, t_stack **lstb)
{
	int	i;
	int	max;
	int	max_bit;
	int	j;

	stack_to_ind(lsta);
	max = stack_size(*lsta) - 1;
	max_bit = 0;
	while (max >> max_bit)
		max_bit++;
	i = 0;
	while (i < max_bit)
	{
		j = -1;
		while (++j < max + 1)
			op_radix(lsta, lstb, (*lsta)->data, i);
		while (stack_size(*lstb))
			operations(lsta, lstb, 5);
		if (is_sorted(*lsta) && !stack_size(*lstb))
			return ((void)(0));
		i++;
	}
}
	// if ((temp >> i) & 1)
	// 	operations(lsta, lstb, 6);
	// else
	// 	operations(lsta, lstb, 4);

void	stack_to_ind(t_stack **lsta)
{
	int		i;
	t_stack	*temp;
	int		*lst;

	temp = *lsta;
	lst = copy_stack(lsta);
	i = 0;
	lst = sort_lst(lst, stack_size(*lsta));
	while (i < stack_size(*lsta))
		i++;
	while (temp)
	{
		i = 0;
		while (i < stack_size(*lsta))
		{
			if (temp->data == lst[i])
			{
				temp->data = i;
				break ;
			}
			i++;
		}
		temp = temp->next;
	}
	free(lst);
}

int	*copy_stack(t_stack	**lsta)
{
	int		*lst;
	int		i;
	t_stack	*temp;

	lst = malloc(sizeof(int) * stack_size(*lsta));
	if (!lst)
		return (0);
	temp = *lsta;
	i = 0;
	while (temp)
	{
		lst[i] = temp->data;
		temp = temp->next;
		i++;
	}
	return (lst);
}

int	*sort_lst(int *lst, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (lst[j] > lst[j + 1])
				swap(&lst[j], &lst[j + 1]);
			j++;
		}
		i++;
	}
	i = 0;
	return (lst);
}

void	swap(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}
