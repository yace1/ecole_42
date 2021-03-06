/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:16:59 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/18 17:56:04 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*copy_mem(int i, unsigned int len, char *dest, char *src)
{
	while (i < (int)len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				i;
	unsigned char	*dst1;
	unsigned char	*src1;

	i = 0;
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	if (dst == 0 && src == 0)
		return (0);
	if (dst1 > src1)
	{
		while (i < (int)len)
		{
			dst1[len - 1] = src1[len - 1];
			len--;
		}
	}
	else
	{
		dst1 = (unsigned char *)copy_mem(i, len, (char *)dst1, (char *)src1);
	}
	dst = (void *restrict)dst1;
	return (dst);
}
// int main()
// {
// 	char str[]= "aaaaafgndfgxvbgl";
//     //void* dest[15];
//     char dst[]= "bbbbbfgndfgxvbgl";
// 	    printf("%s\n",ft_memmove(str, dst, 4));
//     	printf("%s",memmove(str, dst, 4)); 
// }