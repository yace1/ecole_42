/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:51:12 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/12 13:17:53 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <ctype.h>
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
// int main(){
// 	printf("%d\n", isdigit('0'));
// 	printf("%d", ft_isdigit('4'));
// }