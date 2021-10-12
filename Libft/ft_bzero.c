/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:51:31 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/12 11:29:12 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_bzero(char *s, size_t n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
	}
	while (i < n)
	{
		s[i] = 0;
		i++;
	}
}
// int main()
// {
// 	char str[] = "loooof";
//     char str1[] = "loooof";
//     ft_bzero(str, 4);
//     bzero(str1, 4);
//     write(1,str,6);
//     write(1,str1,6); 
// }	