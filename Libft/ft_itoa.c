/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 11:57:49 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/17 17:03:10 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		nb;
	int		i;
	int		neg;

	if (n == -2147483648)
		return(ft_strdup("-2147483648"));
	nb = n;
	i = 0;
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		nb *= -1;
	}
	if (nb < 10 && nb >= 0)
	{
		str = (char *)malloc(sizeof(char) * 2);
		if (!str)
			return (0);
		str[0] = nb + 48;
		str[1] = 0;
		return (str);
	}
	if (neg)
		n *= -1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	if (neg)
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1 + neg));
	if (!str)
		return (0);
	str[i + 1] = 0;
	while (i > neg)
	{
		str[i] = (nb % 10) + 48;
		nb = nb / 10;
		i--;
	}
	str[i] = nb + 48;
	if (neg)
		str[0] = '-';
	return (str);
}

// int main()
// {
// 	printf("le resultat: %s\n",ft_itoa(0));
// 	return (0);
// }