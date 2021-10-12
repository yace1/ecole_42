/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:22:22 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/12 14:50:15 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			return ((char *)&(s[i]));
		}
		i++;
	}
	return (0);
}

// int main()
// {
// 	char str[] = "loooofgndfgxvbgl";
//     char c = 'g';
// 	    printf("%s\n",ft_strchr(str, c));
//     	printf("%s",strchr(str, c)); 
// }