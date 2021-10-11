#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#define BUF_SIZE 	4096

int main()
{
	int fd;
	int ret;
	char **tab;
	int i = 0, line = 0, nbrn = 0, j = 0;
	char buf[BUF_SIZE];
	
	fd = open("file.txt",O_RDONLY);
	if (fd == 1)
		return (1);
	ret = read(fd,buf,BUF_SIZE);
	
	while(buf[i] != '\0')
	{
		if(buf[i] == '\n')
			line += 1;
		i++;
	}
	tab = malloc(sizeof(*tab) * line);
	while( nbrn < line)
	{
		while(tab[nbrn] != '\n')


	}


	printf("%d",line);
}
