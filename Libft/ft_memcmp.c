/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:29:34 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/17 11:18:54 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		i;
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	while (i < (int)n)
	{
		if (*(unsigned char *)(str1 + i) != *(unsigned char *)(str2 + i))
			return (*(unsigned char *)(str1 + i)
					- *(unsigned char *)(str2 + i));
		i++;
	}
	return (0);
}

// int main()
// {
// 	char str[] = "aa";
//     char str1[] = "aa";
// 	    printf("%d\n",ft_memcmp(str, str1, (unsigned int)5));
//     	printf("%d",memcmp(str, str1, (unsigned int)5)); 
// 		return (0);
// }