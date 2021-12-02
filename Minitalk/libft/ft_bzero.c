/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:51:31 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/13 20:32:39 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	dest = s;
	i = 0;
	while (i++ < n)
		*dest++ = 0;
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