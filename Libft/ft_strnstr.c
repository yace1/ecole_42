/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:40:33 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/21 11:14:07 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	c;
	size_t	o_len;
	char	*str;

	i = 0;
	str = (char *)haystack;
	o_len = ft_strlen(needle);
	if (o_len == 0 || haystack == needle)
		return (str);
	while (str[i] != '\0' && i < len)
	{
		c = 0;
		while (str[i + c] != '\0' && needle[c] != '\0'
			&& str[i + c] == needle[c] && i + c < len)
			c++;
		if (c == o_len)
			return (str + i);
		i++;
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