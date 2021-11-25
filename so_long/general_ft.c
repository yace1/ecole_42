/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_ft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:24:35 by yacinebenta       #+#    #+#             */
/*   Updated: 2021/11/25 12:51:27 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strchr2(const char *s, int c, int start)
{
	int		i;

	i = start;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}

size_t	ft_strlen2(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
