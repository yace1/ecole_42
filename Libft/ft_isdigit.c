// #include <stdio.h>
// #include <ctype.h>
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
// int main(){
// 	printf("%d\n", isdigit('0'));
// 	printf("%d", ft_isdigit('4'));
// }