/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:33:26 by yacinebenta       #+#    #+#             */
/*   Updated: 2021/12/20 12:37:28 by ybentaye         ###   ########.fr       */
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

int	stack_size(t_stack *lst)
{
	int		i;
	t_stack	*temp;

	temp = lst;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
