/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:10:05 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/15 10:53:40 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//gestion erreur
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	int				i;
	unsigned char	*dst1;
	unsigned char	*src1;

	i = 0;
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	if (dst == 0 && src == 0)
		return (NULL);
	if (n <= 0 || n >= 4294967295)
		return (dst);
	while (i < (int)n)
	{
		dst1[i] = src1[i];
		i++;
	}
	dst = (void *restrict)dst1;
	return (dst);
}

// int main()
// {
// 	char str[]= "aaaaafgndfgxvbgl";
//     //void* dest[15];
//     char dst[]= "bbbbbfgndfgxvbgl";
// 	    printf("%s\n",memcpy(str, dst, 4));
//     	printf("%s",memcpy(str, dst, 4)); 
// }