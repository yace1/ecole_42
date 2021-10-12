/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:47:16 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/12 12:59:03 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

size_t	*ft_strlcat(char *restrict dst, const char *restrict src, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0' && j < n)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + j);
}
// int main()
// {
// 	char str[]= "aaaaa";
//     //void* dest[15];
//     char dst[15] = "bbbbb";
// 	printf("%d\n",strlcat(str, dst, 6));
// 	printf("%d",ft_strlcat(str, dst, 6)); 
// }