/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:40:33 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/14 14:23:41 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	while (haystack[i] && i + j< (int)len)
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (needle[j + 1] == 0)
				return ((char *)haystack + i);
			j++;
			k++;
		}
		i++;
		k++;
	}
	return (0);
}
// int main()
// {
// 	char str[] = "MZIRIBMZIRIBMZE123";
//     char str1[] = "MZIRIBMZE";
// 	    printf("%s\n",ft_strnstr(str, str1, 9));
//     	printf("%s",strnstr(str, str1, 9)); 
// 		return (0);
// }