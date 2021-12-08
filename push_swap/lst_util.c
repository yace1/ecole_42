/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:33:26 by yacinebenta       #+#    #+#             */
/*   Updated: 2021/12/08 10:33:39 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_add_back(t_stack **alst, t_stack *new)
{
	t_stack	*elem;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	elem = stack_last(*alst);
	elem->next = new;
	new->next = NULL;
}

void	stack_add_front(t_stack **alst, t_stack *new)
{
	(*new).next = *alst;
	*alst = new;
}

t_stack	*stack_last(t_stack *lst)
{
	t_stack	*ptr;

	if (!lst)
		return (lst);
	ptr = lst;
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	return (ptr);
}

t_stack	*before_last(t_stack *lst)
{
	t_stack	*ptr;

	if (!lst)
		return (lst);
	ptr = lst;
	while (ptr->next->next)
	{
		ptr = ptr->next;
	}
	return (ptr);
}


void	print_stack(t_stack **stck)
{
	t_stack	*ptr;

	if (!stck)
		return (void)(0);
	ptr = *stck;
	while (ptr->next)
	{
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
	printf("%d\n", ptr->data);
}