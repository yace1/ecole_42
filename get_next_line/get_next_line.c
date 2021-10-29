/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:43:19 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/28 14:31:51 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

///////////////////////////NEW VERSION////////////////////////

void	free_str(char **str)
{
	free(*str);
	*str = NULL;
}

static char	*return_line(char **str, int ret)
{
	char	*s;
	char	*temp;
	int		i;

	i = 0;
	s = NULL;
	if (ret < 0 || (!ret && (!str || !*str)))
		return (NULL);
	while ((*str)[i] != '\n' && (*str)[i])
		i++;
	if ((*str)[i] == '\n')
	{
		s = ft_substr(*str, 0, i + 1);
		temp = ft_strdup(*str + i + 1);
		free(*str);
		*str = temp;
		if (!**str)
			free_str(str);
		return (s);
	}
	s = ft_strdup(*str);
	free_str(str);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*temp;
	char		*buf;
	int			ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	ret = read(fd, buf, BUFFER_SIZE);
	while (ret > 0)
	{
		buf[ret] = '\0';
		if (!str)
			str = ft_strdup("");
		temp = ft_strjoin(str, buf);
		free(str);
		str = temp;
		if (ft_strchr(buf, '\n'))
			break ;
		ret = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (return_line(&str, ret));
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
