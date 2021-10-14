/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:17:12 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/14 18:59:52 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		len;
	
	len = ft_strlen((char *)s1);
	ptr = (char *)malloc((len + 1* sizeof(char)));
	if (!ptr)
		return(0);
	ft_strlcpy(ptr, s1, len + 1);
	return (ptr);
}

int main()
{
	char str[] = "aaaaaaa";
	    printf("%s\n",ft_strdup(str));
		printf("%s\n",strdup(str));
		return (0);
}