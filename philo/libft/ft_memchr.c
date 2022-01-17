/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:18:02 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/17 10:25:25 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;

	i = 0;
	while (i < (int)n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
		{
			return ((void *)((void *)s + i));
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