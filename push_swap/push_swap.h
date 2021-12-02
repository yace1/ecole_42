/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:14:44 by ybentaye          #+#    #+#             */
/*   Updated: 2021/12/02 11:35:53 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"

typedef struct s_queue
{
	int				data;
	struct s_list 	*next;
	struct s_list 	*prev;
} t_queue;


#endif