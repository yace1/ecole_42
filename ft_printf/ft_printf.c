/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 11:58:40 by ybentaye          #+#    #+#             */
/*   Updated: 2021/11/01 00:22:45 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cnt_arg(const char *str)
{	
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == '%' &&(str[i + 1] == 'c' || str[i + 1] == '%'
				|| str[i + 1] == 's' || str[i + 1] == 'p' || str[i + 1] == 'd'
				|| str[i + 1] == 'u' || str[i + 1] == 'i' || str[i + 1] == 'x'
				|| str[i + 1] == 'x'))
			res++;
		i++;
	}
	return (res);
}

char	detect_arg(const char *str, int i)
{
	if (str[i] == '%' &&(str[i + 1] == 'c' || str[i + 1] == '%'
			|| str[i + 1] == 's' || str[i + 1] == 'p' || str[i + 1] == 'd'
			|| str[i + 1] == 'u' || str[i + 1] == 'i' || str[i + 1] == 'x'
			|| str[i + 1] == 'x'))
		return (str[i + 1]);
	return (0);
}

//return the index to skip the arg and print the value of the arg
void	return_arg(char c, va_list	lst_arg)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(lst_arg, int), 1);
	if (c == 's')
		ft_putstr_fd(va_arg(lst_arg, char *), 1);
	if (c == 'i')
		ft_putnbr_fd(va_arg(lst_arg, int), 1);
	if (c == 'x')
		ft_deca_hexa(va_arg(lst_arg, int));
	if (c == 'p')
		ft_deca_hexa((int)va_arg(lst_arg, void *));
	if (c == '%')
		ft_putchar_fd('%', 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	lst_arg;
	int		i;

	i = 0;
	va_start(lst_arg, str);
	while (str[i])
	{
		if (detect_arg(str, i))
		{
			return_arg(detect_arg(str, i), lst_arg);
			if (!str[i + 2])
				break ;
			i += 2;
		}
		write(1, &str[i], 1);
		i++;
	}
	va_end(lst_arg);
	return (1);
}

// int	main()
// {
// 	int i;
// 	int	*ptr = &i;
// 	i = ft_printf("%ca%s a%x et %p", 'Z', " Hello ", 567, ptr);
// 	return (0);
// }