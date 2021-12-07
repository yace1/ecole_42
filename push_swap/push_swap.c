/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:14:20 by ybentaye          #+#    #+#             */
/*   Updated: 2021/12/08 00:05:57 by yacinebenta      ###   ########.fr       */
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
	t_stack	**lsta;
	t_stack	**lstb;

	lsta = malloc(sizeof(t_stack *));
	if (!lsta)
		return(0);
	lsta = parse_stck(lsta, argv, argc);
	lstb = malloc(sizeof(t_stack *));
	if (!lstb)
		return(0);
	//printf("%d\n", stack_last(*lsta)->data);
	print_stack(lsta);
	operations(lsta, lstb, 1);
	ft_printf("\n\n");
	print_stack(lsta);
	operations(lsta, lstb, 4);
	print_stack(lstb);
	//print_stack(lsta); sa segfault apres pa
	ft_printf("\n");
}

t_stack	**parse_stck(t_stack **lst, char **argv, int argc)
{
	int		i;
	t_stack	*first;
	t_stack	*last;
	t_stack	*temp;

	i = 0;
	first = malloc(sizeof(t_stack));
	if (!first)
		error_check();
	first->data = ft_atoi(argv[1]);
	//printf("%d\n", first->data);
	first->next = NULL;
	last = first;
	i = 2;
	while (i < argc)
	{
		temp = malloc(sizeof(t_stack));
		if (!temp)
			error_check();
		temp->data = ft_atoi(argv[i]);
		temp->next = NULL;
		last->next = temp;
		last = temp;
		//printf("%d\n", last->data);
		i++;
	}
	*lst = first;
	return (lst);
}

/* if using array

	argv = (void *)argv;
	int	*list_a;
	int	*list_b;
	int	i;

	i = 0;
	list_a = malloc(sizeof(int) * (argc));
	list_b = malloc(sizeof(int) * (argc));
	while (i < argc - 1)
	{
		list_a[i] = ft_atoi(argv[i + 1]);
		printf("%d\n",list_a[i]);
		i++;
	}
*/
