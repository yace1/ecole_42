#include "libft.h"


int	search_in(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == (char)c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int 	len_set;
	int		i;
	int     start;
	int		end;

	len_set = ft_strlen((char *)set);
	start = 0;
	end = ft_strlen((char *)s1);
	i = 0;
    if (s1 == 0 && set == 0)
        return (0);
	if (s1 == 0)
		return (0);
    if (set == 0)
		return (ft_strdup(s1));
	while(search_in((char)s1[start], set))
	{
		start++;
	}
	while(search_in((char)s1[end - 1], set))
	{
		end--;
	}
    if (start >= end)
        return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (0);
	while(start < end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = 0;
	return (str);
}

// int main()
// {
// 	char *s1 = "  \t \t \n   \n\n\n\t";
// 	char *s2 = " \n\t";
// 	printf("%s",ft_strtrim(s1,s2));
// 	return (0);
// }

