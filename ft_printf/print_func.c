/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 00:06:21 by yacinebenta       #+#    #+#             */
/*   Updated: 2021/11/03 15:52:45 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		i += ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		i += ft_putchar_fd('-', fd);
		i += ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		i += ft_putnbr_fd(n / 10, fd);
		i += ft_putnbr_fd(n % 10, fd);
	}
	else
		i += ft_putchar_fd(n + '0', fd);
	return (i);
}

int	ft_putuint(unsigned int n, int fd)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i += ft_putchar_fd('-', fd);
		i += ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		i += ft_putnbr_fd(n / 10, fd);
		i += ft_putnbr_fd(n % 10, fd);
	}
	else
		i += ft_putchar_fd(n + '0', fd);
	return (i);
}

int	ft_deca_hexa(unsigned long dec)
{
	int		i;
	int		hexa[10];
	int		rem;

	i = 0;
	rem = 0;
	if (!dec)
		return (ft_putchar_fd('0', 1));
	while (dec > 0)
	{
		rem = dec % 16;
		if (rem < 10)
			hexa[i++] = '0' + rem;
		else
			hexa[i++] = 'A' + (rem - 10);
		dec = dec / 16;
	}
	i--;
	while (i >= 0)
	{
		dec += ft_putchar_fd(hexa[i], 1);
		i--;
	}
	return (dec);
}

int	ft_deca_hexa_min(unsigned long dec)
{
	int		i;
	int		hexa[10];
	int		rem;

	i = 0;
	rem = 0;
	if (!dec)
		return (ft_putchar_fd('0', 1));
	while (dec > 0)
	{
		rem = dec % 16;
		if (rem < 10)
			hexa[i++] = '0' + rem;
		else
			hexa[i++] = 'a' + (rem - 10);
		dec = dec / 16;
	}
	i--;
	while (i >= 0)
	{
		dec += ft_putchar_fd(hexa[i], 1);
		i--;
	}
	return (dec);
}

int	ptr_hexa(unsigned long dec)
{
	int	i;
	int	rem;
	int	hexa[10];

	i = 0;
	ft_putstr_fd("0x", 1);
	rem = 0;
	if (!dec)
		return (ft_putchar_fd('0', 1) + 2);
	while (dec > 0)
	{
		rem = dec % 16;
		if (rem < 10)
			hexa[i++] = '0' + rem;
		else
			hexa[i++] = 'a' + (rem - 10);
		dec = dec / 16;
	}
	i--;
	while (i >= 0)
	{
		dec += ft_putchar_fd(hexa[i], 1);
		i--;
	}
	return (dec + 2);
}
