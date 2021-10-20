/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:33:20 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/20 12:16:37 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *))
{
 	t_list	*new_lst;
	t_list	*begin_lst;
	t_list	**begin_olst;

	new_lst = malloc(sizeof(t_list));
	if (!new_lst)
		return (0);
	begin_lst = new_lst;
	begin_olst = &lst;
	while (lst)
	{
		new_lst->next = malloc(sizeof(t_list));
		if (!new_lst)
			return (0);
		new_lst = new_lst->next;
		lst = lst->next;
	}
	new_lst->next = malloc(sizeof(t_list));
	if (!new_lst)
		return (0);
	ft_lstclear(&(*begin_olst), del);
	ft_lstiter(begin_lst, (void *)(*f));
	return(begin_lst);
}





// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *))
// {
// 	t_list	*new_lst;
// 	t_list	*begin_lst;

// 	new_lst = malloc(sizeof(t_list));
// 	if (!new_lst)
// 		return (NULL);
// 	new_lst->content = f(lst->content);
// 	begin_lst = new_lst;
// 	while (lst)
// 	{
// 		new_lst->next = malloc(sizeof(t_list));
// 		if (!new_lst)
// 			return (0);
// 		new_lst->next->content = f(lst->next->content);
// 		ft_lstdelone();
// 		new_lst = new_lst->next;
// 	}
// 	new_lst->next = NULL;
// 	return (begin_lst);
// }