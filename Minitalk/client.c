/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:52:43 by ybentaye          #+#    #+#             */
/*   Updated: 2021/12/06 13:00:43 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_str(char *str, int pid)
{
	int	i;
	int	bitshift;

	i = 0;
	while (str[i])
	{
		bitshift = -1;
		while (++bitshift < 8)
		{
			if (str[i] & (128 >> bitshift))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(200);
		}
		i++;
	}
}

void	arg_error(void)
{
	ft_printf("Error, wrong arg given, give the pid");
	ft_printf("of the server and a message to send\n");
	exit (0);
}

// check SIGUSR1 SIGUSR2
int	main(int argc, char **argv)
{
	int	pid;
	int	bitshift;

	if (argc != 3)
		arg_error();
	bitshift = 0;
	pid = ft_atoi(argv[1]);
	send_str(argv[2], pid);
	return (0);
}
