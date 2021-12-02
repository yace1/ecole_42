/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:52:48 by ybentaye          #+#    #+#             */
/*   Updated: 2021/12/02 12:25:16 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


//check bitshift
int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	ft_putnbr_fd(argc, 1);
	ft_putstr_fd(argv[1], 1);
	ft_printf("l'id du server: %d", getpid());
	while (1)
		sleep(1);
	return (0);
}