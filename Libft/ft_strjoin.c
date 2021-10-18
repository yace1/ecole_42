/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:06:56 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/18 14:47:47 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*copy_join(char *str, char const *s2, int i)
{
	int	j;

	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len_s2;
	int		len_s1;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	i = 0;
	str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	str = copy_join(str, s2, i);
	return (str);
}

// int main()
// {
// 	char *s1 = "my favorite animal is";
// 	char *s2 = " ";
// 	char *s3 = "the nyancat";
// 	printf("%s",ft_strjoin(ft_strjoin(s1, s2), s3));
// 		return (0);
// }
