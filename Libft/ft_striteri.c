/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:24:11 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/19 17:35:49 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (f == NULL)
		return ((void)0);
	if (s)
	{
		while (s[i])
		{
			(*f)(i, s + i);
			i++;
		}
	}
}

// int main()
// {
// 	char str[] = "aaaaaaa";
// 	ft_striteri(str, tolo);
// 	printf("%s", str);
// 	return (0);
// }