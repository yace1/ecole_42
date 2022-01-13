/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:47:15 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/01/13 01:06:49 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-')
			exit_error();
		i++;
	}
}

void	check_doublon(t_stack **lst)
{
	t_stack	*temp;
	t_stack	*ptr;
	int		i;
	int		j;

	temp = (*lst);
	i = 0;
	while (temp)
	{
		ptr = (*lst);
		j = 0;
		while (ptr)
		{
			if (temp->data == ptr->data && i != j)
			{
				free_stack(lst);
				exit_error();
			}
			ptr = ptr->next;
			j++;
		}
		temp = temp->next;
		i++;
	}
}

void	free_stack(t_stack **lst)
{
	t_stack	*temp;
	t_stack	*begin;	

	if (!lst)
		return ;
	begin = *lst;
	while (begin)
	{
		temp = begin->next;
		free(begin);
		begin = temp;
	}
	*lst = NULL;
	free(*lst);
	free(lst);
}

void	exit_error(void)
{
	ft_printf("Error\n");
	exit (0);
}
