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

void    *ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	int	i;
    unsigned char *dst1;
    unsigned char *src1;

	i = 0;
    dst1 = (unsigned char*)dst;
    src1 = (unsigned char*)src;
	while (i < (int)n)
	{
		dst1[i] = src1[i];
		i++;
	}
    dst = (void *restrict)dst1;
	return (dst);
}

int main()
{
	const void* str[15];
    str = "aaaaafgndfgxvbgl";
    const void* dest[15];
    str = "bbbbbfgndfgxvbgl";
	    printf("%s\n",ft_memcpy(str, 'a', 4));
    	//printf("%s",memcpy(str1, str, 4)); 
}