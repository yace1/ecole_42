/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:38:59 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/19 17:56:48 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*elem;

	elem = ft_lstlast(*lst);
	while (elem != *lst)
	{
		del(elem);
		free(elem->content);
		elem = ft_lstlast(*lst);
	}
	del(elem);
	free(elem->content);
	(*lst)->next = NULL;
}