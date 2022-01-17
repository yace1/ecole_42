/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 11:57:49 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/20 11:26:45 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap(char *tab, int index, int index2)
{
	int	s;

	s = tab[index];
	tab[index] = tab[index2];
	tab[index2] = s;
}

static int	ft_rev_int_tab(char *tab, int size, int i, int neg)
{
	int	a;

	a = 0;
	while (a < size / 2)
	{
		swap(tab, a, size - 1 - a);
		a++;
	}
	if (neg)
		i++;
	return (i);
}

static int	count(int n)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	static	fill_str(char *str, int n, int i)
{
	if (n == 0)
	{
		str[i] = '0';
		return (1);
	}
	else
	{
		while (n)
		{
			str[i] = (n % 10) + '0';
			n /= 10;
			i++;
		}
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		neg;
	char	*str;
	int		len;
	int		i;

	neg = 0;
	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n *= -1;
		neg = 1;
	}
	len = count(n);
	str = malloc(sizeof(char) * (len + neg + 1));
	if (!str)
		return (NULL);
	i = fill_str(str, n, i);
	if (neg)
		str[i] = '-';
	i = ft_rev_int_tab(str, len + neg, i, neg);
	str[i] = 0;
	return (str);
}

// int main()
// {
// 	printf("le resultat: %s\n",ft_itoa(-55));
// 	return (0);
// }