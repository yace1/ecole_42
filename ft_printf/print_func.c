/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 00:06:21 by yacinebenta       #+#    #+#             */
/*   Updated: 2021/11/01 12:19:27 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s == 0)
		return ((void)(0));
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

void	ft_deca_hexa(unsigned int dec)
{
	int		i;
	char	hexa[10];
	int		rem;

	i = 0;
	rem = 0;
	dec = check_neg_hexa(dec);
	while (dec > 0)
	{
		rem = dec % 16;
		if (rem < 10)
			hexa[i++] = '0' + rem;
		else
			hexa[i++] = 'A' + (rem - 10);
		dec = dec / 16;
	}
	while (i >= 0)
	{
		ft_putchar_fd(hexa[i], 1);
		i--;
	}
}

void	ft_deca_hexa_min(unsigned int dec)
{
	int		i;
	char	hexa[100];
	int		rem;

	dec = (unsigned int) dec;
	i = 0;
	rem = 0;
	//dec = check_neg_hexa(dec);
	while (dec > 0)
	{
		rem = dec % 16;
		if (rem < 10)
			hexa[i++] = '0' + rem;
		else
			hexa[i++] = 'a' + (rem - 10);
		dec = dec / 16;
	}
	while (i >= 0)
	{
		ft_putchar_fd(hexa[i], 1);
		i--;
	}
}

int	check_neg_hexa(int n)
{
	if (n == 0)
		ft_putchar_fd('0', 1);
	if (n < 0)
	{
		n *= -1;
	}
	return (n);
}
