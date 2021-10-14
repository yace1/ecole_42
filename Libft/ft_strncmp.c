/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:52:08 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/13 16:45:43 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (--n && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// int main()
// {
// 	char str[] = "1234";
//     char str1[] = "1235";
// 	    printf("%d\n",ft_strncmp(str, str1, (unsigned int)5));
//     	printf("%d",strncmp(str, str1, (unsigned int)5)); 
// }