/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:43:19 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/27 15:01:10 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str;
	char		*rest;
	char		*temp;
	char		buf[BUFFER_SIZE + 1];
	int			i;
	int			ret;

	i = 0;
	ret = 1;
	rest = NULL;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE * sizeof(char));
		buf[ret] = 0;
		if (!str)
			str = ft_strdup(buf);
		else
			str = ft_strjoin(str, buf);
		if (ft_strchr(str, '\n'))
		{
			i = ft_strchr(str, '\n');
			temp = ft_substr(str, 0, i);
			rest = ft_substr(str, i + 1, ft_strlen(str) - i);
			free(str);
			if (rest)
				str = ft_strdup(rest);
			if (temp[0] == 0)
				return (NULL);
			return (temp);
		}
		if (ret != BUFFER_SIZE && ret)
		{
			temp = ft_strdup(str);
			free(str);
			str = NULL;
			if (temp[0] == 0)
				return (NULL);
			return (temp);
		}
		if (!ret)
		{
			if (str)
			{
				temp = ft_strdup(str);
				free(str);
				str = NULL;
				if (temp[0] == 0)
					return (NULL);
				return (temp);
			}
			free(str);
			return (NULL);
		}
		free(str);
	}
	free(str);
	return (NULL);
}

// int main()
// {
// 	int fd;
// 	char	*s;
// 	int	i;

// 	i = 0;
// 	fd = open("texte.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (0);
// 	while(i < 8)
// 	{
// 		s = get_next_line(fd);
// 		printf("%d: %s \n", i, s);
// 		i++;
// 	}
// 	fd = close(fd);
// 	return (0);
// }

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n > 0)
	{
		while (src[i] && i < (n - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
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
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
