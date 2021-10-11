#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int detect(char c, char *charset)
{

}


char	**ft_split(char *str, char* charset)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		j = 0;
		k = 0;
		while (str[i] != charset[k] && charset[k] != 0)
		{
			tab[j] = str[i];
			k++;
		}
		while (str[i + 1] 

	}
}

int main()
{
	char str[] = "abc def, hij:qoj";
	char sep[] = " ,:";
	int i = 0;
	
	while ( i < 5)
	{
		printf("%s",ft_split(str,sep)[i]);
		i++;
	}
}
