// #include <stdio.h>
// #include <ctype.h>
int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 91) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
// int main(){
// 	printf("%d\n", isalnum(' '));
// 	printf("%d", ft_isalnum(' '));
// }