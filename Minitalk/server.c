/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:52:48 by ybentaye          #+#    #+#             */
/*   Updated: 2021/12/03 10:30:41 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_signal(int signum);
//check bitshift
int	main(void)
{
	int	i;

	i = 0;

	ft_printf("l'id du server: %d", getpid());
	signal(SIGUSR1, get_signal);
	while (1)
		sleep(1);
	return (0);
}

void	get_signal(int signum)
{
	ft_printf("got the signal: %d\n", signum);
	exit (0);
}