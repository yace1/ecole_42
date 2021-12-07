/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:52:48 by ybentaye          #+#    #+#             */
/*   Updated: 2021/12/06 12:59:53 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bit_to_char(int signum);

int	main(void)
{
	int	i;

	i = 0;
	ft_printf("server id: %d\n", getpid());
	signal(SIGUSR1, bit_to_char);
	signal(SIGUSR2, bit_to_char);
	while (1)
		pause();
	return (0);
}

void	bit_to_char(int signum)
{
	static int				counter = 128;
	static unsigned char	c = 0;
	static int				bitshift = 8;

	if (signum == SIGUSR1)
	{
		c += counter;
		counter = counter / 2;
	}
	else if (signum == SIGUSR2)
		counter = counter / 2;
	bitshift--;
	if (counter < 1 || bitshift <= 0)
	{
		ft_printf("%c", c);
		counter = 128;
		bitshift = 8;
		c = 0;
	}
}
