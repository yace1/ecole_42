/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:16:59 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/12 11:29:14 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

//gestion erreur
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				i;
	unsigned char	*dst1;
	unsigned char	*src1;

	i = 0;
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	while (i < (int)len)
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
// 	    printf("%s\n",ft_memmove(str, dst, 4));
//     	printf("%s",memmove(str, dst, 4)); 
// }