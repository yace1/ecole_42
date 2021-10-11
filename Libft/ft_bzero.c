#include <unistd.h>
#include <stdio.h>
#include <string.h>

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

void    ft_bzero(char *s, size_t n)
{
    int i;

    i = 0;
    if (n == 0)
    {

    }
    while (i < n)
    {
        s[i] = 0;
        i++;
    }
}

int main()
{
	
	char str[] = "loooof";
    char str1[] = "loooof";
    ft_bzero(str, 4);
    bzero(str1, 4);
    write(1,str,6);
    write(1,str1,6); 
}