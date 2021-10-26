/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lecture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 21:13:24 by ebennace          #+#    #+#             */
/*   Updated: 2021/07/27 17:08:44 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "solver.c"
#include "ft_read.c"


void check_plateaux(char *str);
int main()
{	
	int		fd;
	int		ret;
	char	buf[4096];
	maxsize value;
	fd = open("test3.txt", O_RDONLY);

	ret = read(fd, buf, 4096);
	buf[ret] = '\0';
	printf("%s\n", buf);
	check_plateaux(buf);
	
	printf("nbr ligne %d, nbr char:%d",value.ymax,value.xmax);
}
