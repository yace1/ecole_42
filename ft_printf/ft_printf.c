/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 11:58:40 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/31 13:50:17 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int	ft_printf(const char *str, ...)
{
	va_list	lst_arg;
	int		nb_arg;
	int		i;

	nb_arg = 0;
	i = -1;
	va_start(lst_arg, str);
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1] != '%')
			nb_arg++;
	}
	i = 0;
}

int	main()
{
	int i = ft_printf("salut%d comment%d cavaaa%d");
	printf("%d", i);
	return (0);
}
