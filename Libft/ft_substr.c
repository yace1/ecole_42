/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:33:45 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/18 12:21:23 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char				*ptr;
// 	unsigned int		lim;
// 	unsigned int		i;

// 	i = 0;
// 	ptr = (char *)malloc((len + 1) * sizeof(char));
// 	if (!ptr)
// 		return (0);
// 	lim = start + len;
// 	if (s == 0)
// 		return (0);
// 	if (start >= ft_strlen((char *)s))
// 		return (0);
// 	while (s[start] && start < lim)
// 	{
// 		ptr[i] = s[start];
// 		start++;
// 		i++;
// 	}
// 	ptr[i] = 0;
// 	return (ptr);
// }

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	n_len;

	if (s == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	n_len = ft_strlen(s + start);
	if (n_len < len)
		len = n_len;
	if (!(substr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}

// int main()
// {
// 	char str[] = "aaaaaaa";
// 	    printf("%s\n",ft_strdup(str));
// 		printf("%s\n",strdup(str));
// 		return (0);
// }