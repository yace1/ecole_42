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

// int main()
// {
// 	char *str;
// 	str = "loooofgndfgxvbgl";
// 	    printf("%lu",ft_strlen(str));
//     	printf("%lu",strlen(str));

    
// }