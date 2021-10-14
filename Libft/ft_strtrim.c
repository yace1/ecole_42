#include "libft.h"

int	ft_strind(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	if (needle[0] == 0)
		return (-2);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (needle[j + 1] == 0)
				return (i);
			j++;
			k++;
		}
		i++;
		k++;
	}
	return (-1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int 	len_set;
	int 	len_s1;
    int     i;

    len_s1 = ft_strlen((char *)s1);
    len_set = ft_strlen((char *)set);
    str = (char *)malloc(sizeof(char)* (len_s1 + 1));
    if (!str)
    {
        return (0);
    }
    i = 0;
    if (ft_strind(s1, set) == 0)
    {
        s1 += len_set;
    }
    len_s1 = ft_strlen((char *)s1);
    if (ft_strind(s1, set) != len_s1 - len_set)
        len_set = 0;
    while (s1[i] && i < len_s1 - len_set)
    {
        str[i] = s1[i];
        i++;
    }
    str[i] = '\0';
    return(str);
}

int main()
{
	char *s1 = "----my favorite animal is  ";
	char *s2 = "--";
	printf("%s",ft_strtrim(s1,s2));
		return (0);
}