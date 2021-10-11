// #include <unistd.h>
// #include <stdio.h>
// #include <string.h>
unsigned long	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_memset(char *b, int c, size_t len)
{
	int	i;

	i = 0;
	while (i < (int)len)
	{
		b[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

// int main()
// {
// 	char str[] = "loooofgndfgxvbgl";
//     char str1[] = "loooofgndfgxvbgl";
// 	    printf("%s\n",ft_memset(str, 'a', 4));
//     	printf("%s",memset(str1, 'a', 4)); 
// }