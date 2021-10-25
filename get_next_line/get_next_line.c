/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:43:19 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/25 17:38:46 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF_SIZE 3

char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *str);
static char	*copy_join(char *str, char const *s2, int i);
char		*ft_strdup(const char *s1);
int			ft_strchr(const char *s, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlcpy(char *restrict dst, const char *restrict src, size_t n);


// 1- doit get l'index du \n
// 2- si il reste des lettre dans le buffer apres l'index les mettres dans temp avec substr

char *get_next_line(int fd)
{
	static char	*str;
	char		*rest;
	char		*temp;
	char		buf[BUF_SIZE + 1];
	int			i;
	int			ret;
	
	ret = 1;
	i = 0;
	while (ret > 0)
	{
		ret = read(fd, buf, BUF_SIZE * sizeof(char));
		if (ret == 0)
			return(NULL);
		buf[BUF_SIZE] = 0;
		if (!str)
			str = ft_strdup(buf);
		else
			str = ft_strjoin(str, buf);
		// if (ft_strchr(buf, '\0'))
		// {
		// 	i = ft_strchr(str, '\0');
		// 	temp = ft_substr(str, 0, i);
		// 	return (temp);
		// }
		if (ft_strchr(str, '\n'))
		{
			i = ft_strchr(str, '\n');
			//printf("ici mtn: %s pos:%d\n", str, i);
			temp = ft_substr(str, 0, i);
			rest = ft_substr(str, i + 1, ft_strlen(str) - i);
			free(str);
			str = ft_strdup(rest);
			return (temp);
		}
	}
	return (str);
}

int main()
{
	int fd;
	char	*s;
	int	i;

	i = 0;
	fd = open("texte.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	while(i < 6)
	{
		s = get_next_line(fd);
		printf("string: %s index: %d\n", s, i);
		i++;
	}
	fd = close(fd);
	return (0);
}

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

int	ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (0);
}


char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		len;
	int		i;

	len = ft_strlen((char *)s1);
	i = 0;
	ptr = (char *)malloc((len + 1 * sizeof(char)));
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = 0;
	if (!ptr)
		return (0);
	return (ptr);
}


size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

static char	*copy_join(char *str, char const *s2, int i)
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
