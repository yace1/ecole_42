/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:58:16 by ybentaye          #+#    #+#             */
/*   Updated: 2021/12/14 12:51:37 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*swap_elem(int *lst, int ind1, int ind2);
int		*sort_lst(int *lst, int size);
int		*copy_stack(t_stack	**lsta);

void	stack_to_ind(t_stack **lsta)
{
	int		i;
	t_stack	*temp;
	int		*lst;

	temp = *lsta;
	lst = copy_stack(lsta);
	sort_lst(lst, stack_size(*lsta));
	ft_printf("%d\n",lst[1]);
	while (temp)
	{
		//ft_printf("check la %d\n", stack_size(*lsta));
		i = 0;
		while (i < stack_size(*lsta))
		{
			if (temp->data == lst[i])
			{
				ft_printf("%d %d\n", temp->data, i);
				temp->data = i;
			}
			i++;
		}
		temp = temp->next;
	}
	free(lst);
}

int	*copy_stack(t_stack	**lsta)
{
	int	*lst;
	int	i;
	t_stack	*temp;

	lst = malloc(sizeof(int) * (stack_size(*lsta) + 1));
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
	int	check;

	i = 0;
	check = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (lst[i + 1] > lst[i])
				lst = swap_elem(lst, lst[i + 1], lst[i]);
			check++;
			j++;
		}
		if (!check)
			break ;
		i++;
	}
	return (lst);
}

int	*swap_elem(int *lst, int ind1, int ind2)
{
	int	temp;

	temp = ind1;
	lst[ind1] = lst[ind2];
	lst[ind2] = temp;
	ft_printf("%d\n",lst[1]);
	return (lst);
}