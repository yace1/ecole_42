/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 00:06:21 by yacinebenta       #+#    #+#             */
/*   Updated: 2021/12/02 12:18:01 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuint(unsigned int n, int fd)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i += ft_putchar_fd2('-', fd);
		i += ft_putnbr_fd2(-n, fd);
	}
	else if (n >= 10)
	{
		i += ft_putnbr_fd2(n / 10, fd);
		i += ft_putnbr_fd2(n % 10, fd);
	}
	else
		i += ft_putchar_fd2(n + '0', fd);
	return (i);
}

int	ft_deca_hexa(unsigned long dec)
{
	int		i;
	int		hexa[100];
	int		rem;

	i = 0;
	rem = 0;
	if (!dec)
		return (ft_putchar_fd2('0', 1));
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
		dec += ft_putchar_fd2(hexa[i], 1);
		i--;
	}
	return (dec);
}

void	ft_deca_hexa_min(unsigned long dec, int *i)
{
	if (dec >= 16)
	{
		ft_deca_hexa_min(dec / 16, i);
		ft_deca_hexa_min(dec % 16, i);
	}
	else
	{
		if (dec < 10)
		{
			dec += '0';
			*i += ft_putchar_fd2(dec, 1);
		}
		else if (dec < 16)
		{
			dec += 'W';
			*i += ft_putchar_fd2(dec, 1);
		}
	}
}

int	ptr_hexa(unsigned long dec)
{
	int	i;
	int	rem;
	int	hexa[100];

	i = 0;
	ft_putstr_fd("0x", 1);
	rem = 0;
	if (!dec)
		return (ft_putchar_fd2('0', 1) + 2);
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
		dec += ft_putchar_fd2(hexa[i], 1);
		i--;
	}
	return (dec + 2);
}
