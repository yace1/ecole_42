/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:51:23 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/13 11:49:18 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*str;

	str = (unsigned char *)b;
	i = 0;
	while (i < (int)len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
// int main()
// {
// 	char str[] = "loooofgndfgxvbgl";
//     char str1[] = "loooofgndfgxvbgl";
// 	    printf("%s\n",ft_memset(str, 'a', 6));
//     	printf("%s",memset(str1, 'a', 6)); 
// }