/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:08:39 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/13 19:53:09 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*remove_space(char *str)
{
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
	{
		str++;
	}	
	return (str);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	str = (const char *)remove_space((char *)str);
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
		{
			sign = -1;
		}
		str++;
	}
	while (str[i] != '\0' && (str[i] > 47 && str[i] < 58))
	{
		nb *= 10;
		nb += (str[i] - 48);
		i++;
	}
	return (nb * sign);
}

// int main()
// {
// 	char str[] = " +1234";
// 	    printf("%d\n",atoi(str));
//     	printf("%d",ft_atoi(str)); 
// 		return (0);
// }