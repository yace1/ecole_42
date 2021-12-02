/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:14:20 by ybentaye          #+#    #+#             */
/*   Updated: 2021/12/02 11:35:53 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_check(void)
{
	ft_putstr_fd("error\n", 1);
	exit (0);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 2)
		error_check();
	while (i++ < argc)
		ft_putnbr_fd(ft_atoi(argv[i]))	
}