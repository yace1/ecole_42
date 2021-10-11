// #include <stdio.h>
// #include <ctype.h>
int ft_isprint(int c)
{
	if (c >= 32 && c <= 63)
	{
		return (1);
	}
	else
    {
		return (0);
	}
}
// int main(){
// 	printf("%d\n", isprint('%'));
// 	printf("%d", ft_isprint('%'));
//     return(0);
// }