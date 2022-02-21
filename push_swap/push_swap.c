/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:14:20 by ybentaye          #+#    #+#             */
/*   Updated: 2022/02/19 13:08:34 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst(t_lst list);
void	free_lst(t_lst *lsta, t_lst *lstb);

int	main(int argc, char **argv)
{
	t_lst	*lst_a;
	t_lst	*lst_b;

	lst_a = parsing_lst(argv, argc);
	lst_b = malloc(sizeof(t_lst));
	lst_b->max_len = lst_a->max_len;
	lst_b->lst = malloc(sizeof(int) * lst_b->max_len);
	choose_algo_lst(lst_a, lst_b);
	free_lst(lst_a, lst_b);
}
//print_lst(*lst_a);
//printf("%d\n", getpid());

void	print_stack(t_stack **stck)
{
	t_stack	*ptr;

	if (!stck)
		return ((void)(0));
	if (!*stck)
	{
		ft_printf("vide\n");
		return ((void)(0));
	}
	ptr = *stck;
	while (ptr->next)
	{
		ft_printf("%ld\n", ptr->data);
		ptr = ptr->next;
	}
	ft_printf("%d\n", ptr->data);
}

void	print_lst(t_lst list)
{
	int		i;
	t_lst	*temp;

	temp = &list;
	i = 0;
	while (i < list.len)
	{
		printf("%d: %d\n", i, temp->lst[i]);
		i++;
	}
}

void	free_lst(t_lst *lsta, t_lst *lstb)
{
	free(lsta->lst);
	free(lstb->lst);
	free(lsta);
	free(lstb);
}
