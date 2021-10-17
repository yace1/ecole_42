/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 10:23:25 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/17 13:42:24 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int count_words(char const *s1, char  c)
{
    int		res;
	int		i;

	i = 0;
	res = 0;

	i = 0;
	while (s1[i])
	{
		while (s1[i] != c)
		{
			if (s1[i + 1] == c || s1[i + 1] == 0)
				res++;
			i++;
		}
		i++;
	}
	return (res);
}

char	*skip_words(char *s1, char c)
{
	int	i;
	int	flag;
	int	len;

	i = 0;
	flag = 0;
	while (s1[i] && !flag)
	{
		if (s1[i] == c)
		{
			len = i + 1;
			flag = 1;
		}
		i++;
	}
	s1 += len;
	return (s1);
}

char	*copy_word(char *dst, char const *src, char c)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != c)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

int	count_letter(char const *s1, char c)
{
	int	i;

	i = 0;
	while (s1[i] != c)
	{
		i++;
	}

	return (i);
}

char	*skip_letter(char const *s1, char c)
{	
	int	i;
	int	flag;
	int	len;

	i = 0;
	flag = 0;
	while (s1[i] && !flag)
	{
		if (s1[i] != c)
		{
			len = i + 1;
			flag = 1;
		}
		i++;
	}
	s1 += len - 1;
	return ((char *)s1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		words;
	int		i;

	i = 0;
	words = count_words(s, c);
	if (c == '\0' || s == (void *)0)
		return (0);
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return ((void *)0);
	tab[words] = NULL;
	
	while (i < words)
	{
		s = skip_letter((char *)s,c);
		tab[i] = (char *)malloc(sizeof(char) * count_letter(s,c));
		if (!tab[i])
			return (0);
		copy_word(tab[i], s, c);
		s = skip_words((char *)s,c);
		i++;
	}
	return(tab);
}

// int main()
// {
// 	char *s1 = "\0aa\0bbb";
// 	char c = '\0';
// 	char **tab;
// 	int	i = 0;
// 	int	len = count_words(s1, c);
// 	printf("%d\n",count_letter(s1,c));
// 	printf("%d\n",count_words(s1,c));
// 	//s1 = skip_words(s1,c);
// 	tab = ft_split(s1,c);
// 	while (i < len)
// 	{
// 		printf("%s\n", tab[i]);
// 		i++;
// 	}

// 	return (0);
// }