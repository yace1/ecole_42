/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:18:02 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/12 15:32:43 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i] && i < (int)n)
	{
		if (str[i] == c)
		{
			return ((void *)&(str[i]));
		}
		i++;
	}
	return (0);
}

// int main()
// {
// 	char str[] = "loooofgnd123vbgl";
//     char c = '2';
// 	    printf("%s\n",ft_memchr(str, c, 10));
//     	printf("%s",memchr(str, c, 10)); 
// }