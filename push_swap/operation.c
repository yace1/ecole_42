/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:00:13 by yacinebenta       #+#    #+#             */
/*   Updated: 2021/12/09 12:45:28 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sa_or_sb(t_stack **lst, int op);
static void pa_or_pb(t_stack **lst1, t_stack **lst2, int op);
static void	ra_or_rb(t_stack **lst1, int op);
static void	rra_or_rrb(t_stack **lst1, int op);

/* operations:
1 = sa		2 = sb		3 = ss
4 = pa		5 = pb
6 = ra		7 = rb		8 = rr
9 = rra		10 = rrb	11 = rrr
*/
void	operations(t_stack **lsta, t_stack **lstb, int op)
{
	if (op == 1)
		sa_or_sb(lsta, 1);
	else if (op == 2)
		sa_or_sb(lstb, 2);
	else if (op == 3)
	{
		sa_or_sb(lsta, 28);
		sa_or_sb(lstb, 0);
	}
	else if (op == 4)
		pa_or_pb(lsta, lstb, 4);
	else if (op == 5)
		pa_or_pb(lstb, lsta, 5);
	else if (op == 6)
		ra_or_rb(lsta, 6);
	else if (op == 7)
		ra_or_rb(lstb, 7);
	else if (op == 8)
	{
		ra_or_rb(lsta, 8);
		ra_or_rb(lsta, 8);
	}
	else if (op == 9)
		rra_or_rrb(lsta, 9);
	else if (op == 10)
		rra_or_rrb(lstb, 10);
	else if (op == 11)
	{
		rra_or_rrb(lsta, 11);
		rra_or_rrb(lstb, 0);
	}
}

static void	sa_or_sb(t_stack **lst, int op)
{
	t_stack	*temp;
	
	temp = *lst;
	(*lst) = (*lst)->next;
	temp->next = (*lst)->next;
	(*lst)->next = &(*temp);
	if (op == 1)
		ft_printf("sa\n");
	if (op == 2)
		ft_printf("sb\n");
	if (op == 3)
		ft_printf("ss\n");
}

//check leak
static void pa_or_pb(t_stack **lst1, t_stack **lst2, int op)
{
	t_stack	*new;

	if ((*lst1) == NULL)
		return((void)0);
	new = malloc(sizeof(t_stack));
	if (!new)
		return ((void)0);
	new->data = (*lst1)->data;
	stack_add_front(lst2, new);
	(*lst1) = (*lst1)->next;
	if (op == 4)
		ft_printf("pa\n");
	if (op == 5)
		ft_printf("pb\n");
}

static void	ra_or_rb(t_stack **lst1, int op)
{
	t_stack *last;
	t_stack *temp;

	last = stack_last(*lst1);
	temp = (*lst1);
	(*lst1) = (*lst1)->next;
	last->next = temp;
	temp->next = NULL;
	// last = stack_last(*lst1);
	// prev_last = before_last(*lst1);
	// temp = (*lst1);
	// last->next = (*lst1)->next;
	// (*lst1) = last;
	// prev_last->next = temp;
	// temp->next = NULL;
	if (op == 6)
		ft_printf("ra\n");
	if (op == 7)
		ft_printf("rb\n");
	if (op == 8)
		ft_printf("rr\n");
}

static void	rra_or_rrb(t_stack **lst1, int op)
{
	t_stack *last;
	t_stack *prev_last;	
	t_stack *temp;

	last = stack_last(*lst1);
	prev_last = before_last(*lst1);
	temp = (*lst1);
	(*lst1) = last;
	(*lst1)->next = temp;
	prev_last->next = NULL;
	// (*lst1) = last;
	// prev_last->next = temp;
	// temp->next = NULL;
	if (op == 9)
		ft_printf("rra\n");
	if (op == 10)
		ft_printf("rrb\n");
}