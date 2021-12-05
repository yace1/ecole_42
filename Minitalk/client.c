/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:52:43 by ybentaye          #+#    #+#             */
/*   Updated: 2021/12/03 13:48:32 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int send_str(char *str, int sign, int len)
{
	int	i;
	int	j;

	j = 0;
	while (j < len)
	{
		while (i < 7)
		{
			i = 0;
			if ((str[j] >> i) & 1)
				kill(9316, SIGUSR1);
			else
				kill(9316, SIGUSR2);
			i++;
			sleep(0.1);
		}
		j++;
	}
}

// check SIGUSR1 SIGUSR2
int	main(int argc, char **argv)
{
	int sig;
	int	sign;
	int	len;

	sign = ft_atoi(argv[1]);
	len = ft_strlen(argv[2]);
	sig = SIGUSR1;
	ft_printf("le signal: %d\n", sig);
	kill(9316, SIGUSR1);
	return (0);
}