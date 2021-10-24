/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:33:20 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/21 17:31:26 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strdup2(const char *s1)
{
	char	*ptr;
	int		len;

	len = ft_strlen((char *)s1);
	ptr = (char *)malloc((len + 1 * sizeof(char)));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s1, len + 1);
	return (ptr);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*begin_lst;

	if (!lst || !f)
		return (NULL);
	begin_lst = ft_lstnew(f(lst->content));
	new_lst = begin_lst;
	while (lst->next)
	{
		lst = lst->next;
		new_lst->next = ft_lstnew(ft_strdup2(f(lst->content)));
		if (new_lst->next == NULL)
		{
			ft_lstclear(&begin_lst, del);
			return (NULL);
		}
		new_lst = new_lst->next;
	}
	return (begin_lst);
}

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
// {
// 	t_list	*begin;
// 	t_list	*work;

// 	if (lst != NULL && f != NULL)
// 	{
// 		begin = ft_lstnew(f(lst->content));
// 		work = begin;
// 		while (lst->next)
// 		{
// 			lst = lst->next;
// 			if ((work->next = ft_lstnew(ft_strdup(f(lst->content)))) == NULL)
// 			{
// 				ft_lstclear(&begin, del);
// 				return (NULL);
// 			}
// 			work = work->next;
// 		}
// 		return (begin);
// 	}
// 	return (NULL);
// }
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