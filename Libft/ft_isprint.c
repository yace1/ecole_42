/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:51:19 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/12 11:29:10 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <ctype.h>
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 63)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
// int main(){
// 	printf("%d\n", isprint('%'));
// 	printf("%d", ft_isprint('%'));
//     return(0);
// }