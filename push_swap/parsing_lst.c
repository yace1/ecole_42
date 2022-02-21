/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:37:53 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/02/20 14:36:36 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_algo_lst(t_lst *lsta, t_lst *lstb)
{
	int	nb;

	nb = lsta->len;
	if (is_lst_sorted(lsta))
		return ((void)(0));
	else if (nb == 0)
		error_check();
	else if (nb == 1)
		exit (0);
	else if (nb == 3)
		less_than3_lst(lsta, lstb);
	else if (nb == 5)
		less_than5_lst(lsta, lstb);
	else
		algo_radix_lst(lsta, lstb);
}

t_lst	*parsing_lst(char **argv, int argc)
{
	char	*str;
	t_lst	*list_a;

	if (argc < 2)
		exit (0);
	if (argc == 2)
	{
		str = argv[1];
		check_char(str);
		list_a = split_parsing(ft_split(str, ' '),
				count_words(str, ' '));
		check_dbl_lst(list_a);
	}
	else
	{
		list_a = nrml_lst_parsing(argv, argc);
		check_dbl_lst(list_a);
	}
	return (list_a);
}

void	free_splt(char **str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

t_lst	*split_parsing(char **str, int size)
{
	int		i;
	t_lst	*list;

	list = malloc(sizeof(t_lst));
	if (!list)
		return (0);
	list->lst = malloc(sizeof(int) * size);
	list->len = size;
	list->max_len = size;
	i = 0;
	while (i < size)
	{
		list->lst[i] = ft_atol(str[i]);
		i++;
	}
	free_splt(str, size);
	return (list);
}

t_lst	*nrml_lst_parsing(char **str, int size)
{
	int		i;
	int		j;
	t_lst	*list;

	list = malloc(sizeof(t_lst));
	if (!list)
		return (0);
	list->lst = malloc(sizeof(int) * size);
	list->len = size - 1;
	list->max_len = size;
	i = 0;
	j = 1;
	while (j < size)
	{
		list->lst[i] = ft_atol(str[j]);
		i++;
		j++;
	}
	return (list);
}
