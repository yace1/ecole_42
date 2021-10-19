/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:02:19 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/19 17:36:34 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*elem;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	elem = ft_lstlast(*alst);
	elem->next = new;
	new->next = NULL;
}
