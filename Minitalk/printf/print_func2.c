/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:26:14 by yacinebenta       #+#    #+#             */
/*   Updated: 2021/12/02 12:18:06 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd2(char *s, int fd)
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

int	ft_putchar_fd2(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putnbr_fd2(int n, int fd)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		i += ft_putstr_fd2("-2147483648", fd);
	else if (n < 0)
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
