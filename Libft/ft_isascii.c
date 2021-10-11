// #include <stdio.h>
// #include <ctype.h>
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
// int main(){
// 	printf("%d\n", isascii(49));
// 	printf("%d", ft_isascii(49));
//     return(0);
// }
