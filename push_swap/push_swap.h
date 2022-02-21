/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:14:44 by ybentaye          #+#    #+#             */
/*   Updated: 2022/02/19 13:02:42 by yacinebenta      ###   ########.fr       */
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
	long			data;
	struct s_stack	*next;
}	t_stack;

typedef struct s_lst
{
	int		*lst;
	int		len;
	int		max_len;
}	t_lst;

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
void	up_down(t_stack	**lsta, t_stack	**lstb, int index);
int		find_max_index(t_stack *lst);
void	up_down_move(t_stack	**lsta, t_stack	**lstb, int index);
int		is_sorted(t_stack *lst);
int		max_index(t_stack *lst, int index);
void	stack_to_ind(t_stack **lsta);
int		find_max(t_stack *lst);
void	algo_radix(t_stack **lsta, t_stack **lstb);
void	free_stack(t_stack **lst);
void	exit_error(void);
void	check_doublon(t_stack **lst);
void	check_char(char *str);
t_stack	**parsing(t_stack **lst, char **argv, int argc);
void	less_than5(t_stack **lsta, t_stack **lstb);
void	less_than3(t_stack **lsta, t_stack **lstb);
void	choose_algo(t_stack **lsta, t_stack **lstb);
void	double_operation(t_stack **lsta, t_stack **lstb, int op);
void	rra_or_rrb(t_stack **lst1, int op);
void	ra_or_rb(t_stack **lst1, int op);
void	pa_or_pb(t_stack **lst1, t_stack **lst2, int op);
void	sa_or_sb(t_stack **lst, int op);
void	op_radix(t_stack **lsta, t_stack **lstb, int t, int i);
void	error_check(void);
//with int table instead of linked list
t_lst	*parsing_lst(char **argv, int argc);
void	check_dbl_lst(t_lst *list);
t_lst	*split_parsing(char **str, int size);
t_lst	*nrml_lst_parsing(char **str, int size);
void	operations_lst(t_lst *lsta, t_lst *lstb, int op);
void	sa_or_sb_lst(t_lst *list, int op);
void	pa_or_pb_lst(t_lst *list_a, t_lst *list_b, int op);
void	ra_or_rb_lst(t_lst *list_a, int op);
void	rra_or_rrb_lst(t_lst *list_a, int op);
void	double_operation_lst(t_lst *lsta, t_lst *lstb, int op);
void	op_radix_lst(t_lst *lsta, t_lst *lstb, int t, int i);
void	algo_radix_lst(t_lst *lsta, t_lst *lstb);
void	print_lst(t_lst list);
void	less_than3_lst(t_lst *lsta, t_lst *lstb);
void	less_than5_lst(t_lst *lsta, t_lst *lstb);
int		is_lst_sorted(t_lst *lst);
void	choose_algo_lst(t_lst *lsta, t_lst *lstb);
void	free_lst(t_lst *lsta, t_lst *lstb);
int		*update_lst_b(t_lst *list_a, t_lst *list_b, int *cp_b);
int		*update_lst_a(t_lst *list_a, int *cp_a);
void	swap(int *xp, int *yp);
int		*sort_lst(int *lst, int size);
#endif