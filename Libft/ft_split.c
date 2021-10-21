/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 10:23:25 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/21 11:13:05 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static char			**free_split(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static unsigned int	count_words(char const *s, char c)
{
	unsigned int	i;
	unsigned int	nb_strs;

	if (!s[0])
		return (0);
	i = 0;
	nb_strs = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_strs++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_strs++;
	return (nb_strs);
}

static void			ft_get_next_str(char **next_str, unsigned int *next_str_len,
					char c)
{
	unsigned int i;

	*next_str += *next_str_len;
	*next_str_len = 0;
	i = 0;
	while (**next_str && **next_str == c)
		(*next_str)++;
	while ((*next_str)[i])
	{
		if ((*next_str)[i] == c)
			return ;
		(*next_str_len)++;
		i++;
	}
}

char				**ft_split(char const *s, char c)
{
	char			**tab;
	char			*next_str;
	unsigned int	next_str_len;
	unsigned int	nb_strs;
	unsigned int	i;

	if (!s)
		return (NULL);
	nb_strs = count_words(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (nb_strs + 1))))
		return (NULL);
	i = 0;
	next_str = (char *)s;
	next_str_len = 0;
	while (i < nb_strs)
	{
		ft_get_next_str(&next_str, &next_str_len, c);
		tab[i] = (char *)malloc(sizeof(char) * (next_str_len + 1));
			if (!tab[i])
				return (free_split(tab));
		ft_strlcpy(tab[i], next_str, next_str_len + 1);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}


//////////////////// OLD SPLIT VERSION BELLOW ////////////////////////
//////////////////////////////////////////////////////////////////////


// // selector == 1 -> skip normal letter (non delimitor)
// static char	*skip_letter(char const *s1, char c, int selector)
// {	
// 	int	i;
// 	int	flag;
// 	int	len;

// 	i = 0;
// 	flag = 0;
// 	while (s1[i] && !flag)
// 	{
// 		if (s1[i] != c && !selector)
// 		{
// 			len = i + 1;
// 			flag = 1;
// 		}
// 		if (s1[i] == c && selector)
// 		{
// 			len = i + 1;
// 			flag = 1;
// 		}
// 		i++;
// 	}
// 	if (!selector)
// 		s1 += len - 1;
// 	else
// 		s1 += len;
// 	return ((char *)s1);
// }

// //	selector == 1 -> count letter
// static int	count_words(char const *s1, char c, int selector)
// {
// 	int	res;
// 	int	i;

// 	i = 0;
// 	res = 0;
// 	if (selector == 1)
// 	{
// 		while (s1[i] != c && s1[i])
// 			i++;
// 		return (i);
// 	}
// 	while (s1[i])
// 	{
// 		while (s1[i] != c && s1[i] != '\0' && !selector)
// 		{
// 			if (s1[i + 1] == c || s1[i + 1] == 0)
// 			{
// 				res++;
// 				break ;
// 			}
// 			i++;
// 		}
// 		i++;
// 	}
// 	return (res);
// }

// static char	*copy_word(char *dst, char const *src, char c)
// {
// 	int	i;

// 	i = 0;
// 	while (src[i] && src[i] != c)
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = 0;
// 	return (dst);
// }

// static char	**free_tab(char **tab, int size)
// {
// 	while (size >= 0)
// 	{
// 		free(tab[size]);
// 		size--;
// 	}
// 	free (tab);
// 	return (0);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**tab;
// 	int		words;
// 	int		i;

// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	words = count_words(s, c, 0);
// 	tab = (char **)malloc(sizeof(char *) * (words + 1));
// 	if (!tab)
// 		return ((void *)0);
// 	tab[words] = NULL;
// 	while (i < words)
// 	{
// 		s = skip_letter((char *)s, c, 0);
// 		tab[i] = (char *)malloc(sizeof(char) * count_words(s, c, 1));
// 		if (!tab[i])
// 			return (free_tab(tab, i));
// 		copy_word(tab[i], s, c);
// 		s = skip_letter((char *)s, c, 1);
// 		i++;
// 	}
// 	return (tab);
// }

// int main()
// {
// 	char *s1 = "tripouille";
// 	char c = ' ';
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