/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:52:08 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/12 15:15:35 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (s1[i] != 0 && s2[i] != 0 && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

// int main()
// {
// 	char str[] = "aaacaaaaaaaakaaa";
//     char str1[] = "aaacaaaaaaakaaa";
// 	    printf("%d\n",ft_strncmp(str, str1, (unsigned int)5));
//     	printf("%d",strncmp(str, str1, (unsigned int)5)); 
// }