/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:14:44 by ybentaye          #+#    #+#             */
/*   Updated: 2021/12/09 13:24:53 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

void	stack_add_back(t_stack **alst, t_stack *new);
void	stack_add_front(t_stack **alst, t_stack *new);
t_stack	**parse_stck(t_stack **lst, char **argv, int argc);
void	print_stack(t_stack **stck);
t_stack	*stack_last(t_stack *lst);
t_stack	*before_last(t_stack *lst);
void	operations(t_stack **lsta, t_stack **lstb, int op);
void	push_min(t_stack **lsta, t_stack **lstb);
void	push_min_all(t_stack **lsta, t_stack **lstb,int	size_stack);

#endif