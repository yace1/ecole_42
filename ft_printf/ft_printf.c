/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 11:58:40 by ybentaye          #+#    #+#             */
/*   Updated: 2021/11/08 11:18:55 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	detect_arg(const char *str, int i)
{
	if (str[i] == '%' && (str[i + 1] == 'c' || str[i + 1] == '%'
			|| str[i + 1] == 's' || str[i + 1] == 'p' || str[i + 1] == 'd'
			|| str[i + 1] == 'u' || str[i + 1] == 'i' || str[i + 1] == 'x'
			|| str[i + 1] == 'X'))
		return (str[i + 1]);
	return (0);
}

//return the index to skip the arg and print the value of the arg
int	return_arg(char c, va_list	lst_arg)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_putchar_fd(va_arg(lst_arg, int), 1);
	else if (c == 's')
		i = ft_putstr_fd(va_arg(lst_arg, char *), 1);
	else if (c == 'i')
		i = ft_putnbr_fd(va_arg(lst_arg, int), 1);
	else if (c == 'd')
		i = ft_putnbr_fd(va_arg(lst_arg, int), 1);
	else if (c == 'u')
		i = ft_putuint(va_arg(lst_arg, unsigned int), 1);
	else if (c == 'x')
		ft_deca_hexa_min(va_arg(lst_arg, unsigned int), &i);
	else if (c == 'X')
		i = ft_deca_hexa(va_arg(lst_arg, unsigned int));
	else if (c == 'p')
		i = ptr_hexa((unsigned long)va_arg(lst_arg, void *));
	else if (c == '%')
		i = ft_putchar_fd('%', 1);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	lst_arg;
	int		i;
	int		j;

	i = 0;
	va_start(lst_arg, str);
	j = 0;
	while (str[i])
	{
		while (detect_arg(str, i))
		{
			j += return_arg(detect_arg(str, i), lst_arg);
			i += 2;
			if (!str[i])
				break ;
		}
		if (str[i])
			write(1, &str[i], 1);
		else
			break ;
		i++;
		j++;
	}
	va_end(lst_arg);
	return (j);
}

// int	main()
// {
// 	int i, j;
// 	int	*ptr;
// 	ptr = &i;
// 	// printf("|--result vrai: %d\n\n", j);// 
// 	j = printf(" %x%x%x%x%x%x%x%x ",42,42,42,42,42,42,42,42);
// 	printf("|--result vrai: %d\n\n", j);
// 	i = ft_printf(" %x%x%x%x%x%x%x%x ",42,42,42,42,42,42,42,42, 42);
// 	printf("|--result copy: %d\n\n", i);
// 	return (0);
// }