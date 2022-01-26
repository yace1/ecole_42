/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:48:53 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/01/26 15:40:04 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_error(void)
{
	printf("Argument Error\n");
	exit (1);
}

void	free_my_hommies(t_phil *phil)
{
	printf("All my homies are free\n");
	free(phil->lst);
	exit (0);
}
// should also free the philo malloc in main, error for the moment
// free(&phil);
