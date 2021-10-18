/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 10:23:25 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/18 17:55:53 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// selector == 1 -> skip normal letter (non delimitor)
char	*skip_letter(char const *s1, char c, int selector)
{	
	int	i;
	int	flag;
	int	len;

	i = 0;
	flag = 0;
	while (s1[i] && !flag)
	{
		if (s1[i] != c && !selector)
		{
			len = i + 1;
			flag = 1;
		}
		if (s1[i] == c && selector)
		{
			len = i + 1;
			flag = 1;
		}
		i++;
	}
	if (!selector)
		s1 += len - 1;
	else
		s1 += len;
	return ((char *)s1);
}

//	selector == 1 -> count letter
int	count_words(char const *s1, char c, int selector)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	if (selector == 1)
	{
		while (s1[i] != c)
		{
			i++;
		}
		return (i);
	}
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

char	**free_tab(char **tab, int size)
{
	while (size >= 0)
	{
		free(tab[size]);
		size--;
	}
	free (tab);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		words;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	words = count_words(s, c, 0);
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return ((void *)0);
	tab[words] = NULL;
	while (i < words)
	{
		s = skip_letter((char *)s, c, 0);
		tab[i] = (char *)malloc(sizeof(char) * count_words(s, c, 1));
		if (!tab[i])
			return (free_tab(tab, i));
		copy_word(tab[i], s, c);
		s = skip_letter((char *)s, c, 1);
		i++;
	}
	return (tab);
}

// int main()
// {
// 	char *s1 = "\0aa\0bbb";
// 	char c = '\0';
// 	char **tab;
// 	int	i = 0;
// 	int	len = count_words(s1, c, 0);
// 	printf("%d\n",count_words(s1,c, 1));
// 	printf("%d\n",count_words(s1,c, 0));
// 	//s1 = skip_words(s1,c);
// 	tab = ft_split(s1,c);
// 	while (i < len)
// 	{
// 		printf("%s\n", tab[i]);
// 		i++;
// 	}

// 	return (0);
// }