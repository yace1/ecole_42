/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:14:44 by ybentaye          #+#    #+#             */
/*   Updated: 2021/12/14 12:32:05 by ybentaye         ###   ########.fr       */
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

typedef struct s_chunk
{
	int		max;
	int		min;
	int		size;
}	t_chunk;

void	stack_add_back(t_stack **alst, t_stack *new);
void	stack_add_front(t_stack **alst, t_stack *new);
t_stack	**parse_stck(t_stack **lst, char **argv, int argc);
t_stack	**parse_stck2(t_stack **lst, char **str, int size);
void	print_stack(t_stack **stck);
t_stack	*stack_last(t_stack *lst);
t_stack	*before_last(t_stack *lst);
void	operations(t_stack **lsta, t_stack **lstb, int op);
void	push_min(t_stack **lsta, t_stack **lstb);
void	push_min_all(t_stack **lsta, t_stack **lstb, int size_stack);
int		stack_size(t_stack *lst);
void	push_all_back(t_stack **lsta, t_stack **lstb);
void	algo_min(t_stack **lsta, t_stack **lstb);
void	chunk_algo(t_stack **lsta, t_stack **lstb);
void	up_down(t_stack	**lsta, t_stack	**lstb, int index);
int		find_max_index(t_stack *lst);
void	up_down_move(t_stack	**lsta, t_stack	**lstb, int index);
int		is_sorted(t_stack *lst);
int		max_index(t_stack *lst, int index);
void	stack_to_ind(t_stack **lsta);

#endif