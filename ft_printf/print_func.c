/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 00:06:21 by yacinebenta       #+#    #+#             */
/*   Updated: 2021/11/02 12:45:54 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int		i;
	char	*snull;

	snull = "(null)";
	i = 0;
	if (s == 0)
	{
		while (snull[i])
		{
			write(fd, &snull[i], 1);
			i++;
		}
	}
	if (s != 0)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
	return (i);
}

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

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

int	ft_deca_hexa(unsigned long dec)
{
	int		i;
	char	hexa[10];
	int		rem;

	i = 0;
	rem = 0;
	dec = check_neg_hexa(dec);
	if (!dec)
		return (1);
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
	char	hexa[10];
	int		rem;

	i = 0;
	rem = 0;
	dec = check_neg_hexa(dec);
	if (!dec)
		return (1);
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

int	check_neg_hexa(int n)
{
	if (n == 0)
		ft_putchar_fd('0', 1);
	return (n);
}

int	check_exeption_hexa(unsigned long n)
{
	if (!n)
		return (1);
	else
		return (0);
	// if (n == -9223372036854775808)
	// 	ft_putstr_fd("-8000000000000000", 1);
	// return(17);
}

int	ptr_hexa(unsigned long dec)
{
	int i;
	int rem;
	int hexa[100];

	i = 0;
	ft_putstr_fd("0x", 1);
	rem = 0;
	dec = check_neg_hexa(dec);
	if (!dec)
		return (1);
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
	return (dec + 2);
}
