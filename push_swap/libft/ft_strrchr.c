/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:22:22 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/17 17:53:21 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	while (i >= 0)
	{
		if (*(char *)(s + i) == (char)c)
		{
			return ((char *)(s + i));
		}
		i--;
	}
	return (0);
}

// int main()
// {
// 	char str[] = "123456";
//     char c = '6';
// 	    printf("%s\n",ft_strrchr(str, c));
//     printf("%s",strrchr(str, c)); 
// }