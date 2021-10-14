#include "libft.h"


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int 	len_s2;
	int 	len_s1;
	int		i;
	int		j;

	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	i = 0;
	str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!str)
		return (0);
	if (!s1 && !s2)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return(str);
}

// int main()
// {
// 	char *s1 = "my favorite animal is";
// 	char *s2 = " ";
// 	char *s3 = "the nyancat";
// 	printf("%s",ft_strjoin(ft_strjoin(s1, s2), s3));
// 		return (0);
// }
