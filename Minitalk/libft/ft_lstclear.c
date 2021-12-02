/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:38:59 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/20 12:19:20 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*begin;	

	if (!lst)
		return ;
	begin = *lst;
	while (begin)
	{
		temp = begin->next;
		if (del)
			del(begin->content);
		free(begin);
		begin = temp;
	}
	*lst = NULL;
}
