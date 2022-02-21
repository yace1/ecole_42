/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:29:31 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/02/19 13:10:01 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* operations:
1 = sa		2 = sb		3 = ss
4 = pb		5 = pa
6 = ra		7 = rb		8 = rr
9 = rra		10 = rrb	11 = rrr
*/
void	operations_lst(t_lst *lsta, t_lst *lstb, int op)
{
	if (op == 1)
		sa_or_sb_lst(lsta, 1);
	else if (op == 2)
		sa_or_sb_lst(lstb, 2);
	else if (op == 3)
		double_operation_lst(lsta, lstb, 3);
	else if (op == 4)
		pa_or_pb_lst(lsta, lstb, 4);
	else if (op == 5)
		pa_or_pb_lst(lstb, lsta, 5);
	else if (op == 6)
		ra_or_rb_lst(lsta, 6);
	else if (op == 7)
		ra_or_rb_lst(lstb, 7);
	else if (op == 8)
		double_operation_lst(lsta, lstb, 8);
	else if (op == 9)
		rra_or_rrb_lst(lsta, 9);
	else if (op == 10)
		rra_or_rrb_lst(lstb, 10);
	else if (op == 11)
		double_operation_lst(lsta, lstb, 11);
}

void	sa_or_sb_lst(t_lst *list, int op)
{
	int	temp;

	temp = list->lst[0];
	list->lst[0] = list->lst[1];
	list->lst[1] = temp;
	if (op == 1)
		ft_printf("sa\n");
	if (op == 2)
		ft_printf("sb\n");
	if (op == 3)
		ft_printf("ss\n");
}

//need to check which is pa and which is pb
// il faut gerer la lengh (reduir dans l'un et augmenter dans l autre)
void	pa_or_pb_lst(t_lst *list_a, t_lst *list_b, int op)
{
	int	i;
	int	j;
	int	*copy_b;
	int	*copy_a;

	copy_b = malloc(sizeof(int) * list_a->max_len);
	copy_a = malloc(sizeof(int) * list_a->max_len);
	if (!copy_b || !copy_a)
		return ((void)(0));
	copy_b = update_lst_b(list_a, list_b, copy_b);
	list_a->len--;
	list_b->len++;
	i = -1;
	j = 0;
	while (++i < list_a->len && ++j)
		copy_a[i] = list_a->lst[j];
	free(list_b->lst);
	free(list_a->lst);
	list_b->lst = copy_b;
	list_a->lst = copy_a;
	if (op == 4)
		ft_printf("pb\n");
	if (op == 5)
		ft_printf("pa\n");
}

void	ra_or_rb_lst(t_lst *list_a, int op)
{
	int	i;
	int	j;
	int	*copy;

	copy = malloc(sizeof(int) * list_a->len);
	if (!copy)
		return ((void)(0));
	i = 0;
	j = 1;
	copy[list_a->len - 1] = list_a->lst[0];
	while (j < list_a->len)
	{
		copy[i] = list_a->lst[j];
		j++;
		i++;
	}
	free(list_a->lst);
	list_a->lst = copy;
	if (op == 6)
		ft_printf("ra\n");
	if (op == 7)
		ft_printf("rb\n");
	if (op == 8)
		ft_printf("rr\n");
}

void	rra_or_rrb_lst(t_lst *list_a, int op)
{
	int	i;
	int	j;
	int	*copy;

	copy = malloc(sizeof(int) * list_a->max_len);
	if (!copy)
		return ((void)(0));
	i = 0;
	j = 1;
	copy[0] = list_a->lst[(list_a->len) - 1];
	while (j < list_a->len)
	{
		copy[j] = list_a->lst[i];
		j++;
		i++;
	}
	free(list_a->lst);
	list_a->lst = copy;
	if (op == 9)
		ft_printf("rra\n");
	if (op == 10)
		ft_printf("rrb\n");
}
