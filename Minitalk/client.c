/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:52:43 by ybentaye          #+#    #+#             */
/*   Updated: 2021/12/02 12:29:21 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// check SIGUSR1 SIGUSR2
int	main()
{
	int sig;

	sig = SIGUSR1;
	ft_printf("le signal: %d\n", sig);
	return (0);
}