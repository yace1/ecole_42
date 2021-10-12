/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:22:22 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/12 14:48:59 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = 0;
	while (s[i])
	{
		i++;
	}
	i--;
	while (s[i] && i >= 0)
	{
		if (s[i] == c)
		{
			str = (char *)&s[i];
			return (str);
		}
		i--;
	}
	return (0);
}

// int main()
// {
// 	char str[] = "loooofgndfgxvbgl";
//     char c = 'o';
// 	    printf("%s\n",ft_strrchr(str, c));
//     	printf("%s",strrchr(str, c)); 
// }