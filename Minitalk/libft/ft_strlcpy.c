/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:22:00 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/13 13:24:32 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n > 0)
	{
		while (src[i] && i < (n - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
	{
		i++;
	}
	return (i);
}

// int main()
// {
// 	char str[]= "aaaaaf";
//     //void* dest[15];
//     char dst[15];
// 	printf("%d\n",strlcpy(str, dst, 6));
// 	printf("%d",ft_strlcpy(str, dst, 6)); 
// }