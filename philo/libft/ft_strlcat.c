/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:47:16 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/18 12:16:12 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	res;
	unsigned int	i;
	unsigned int	j;

	src_len = ft_strlen((char *)src);
	dest_len = ft_strlen((char *)dst);
	i = 0;
	j = dest_len;
	if (dstsize - 1 > dest_len && dstsize > 0)
	{
		while (src[i] && dest_len + i < dstsize - 1)
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = '\0';
	}
	if (dest_len >= dstsize)
		res = src_len + dstsize;
	else
		res = src_len + dest_len;
	return (res);
}
// int main()
// {
// 	char str[]= "acaa";
//
//     char dst[15] = "BB";
// 	char dst1[15] = "BB";
// 
// 	printf("%zu\n",strlcat(dst, str, 2));
// 	printf("%s\n", dst);
// 	printf("%zu\n",ft_strlcat(dst1, str, 2));
// 	printf("%s", dst1);
// }