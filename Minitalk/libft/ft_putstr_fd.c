/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:32:07 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/18 11:40:38 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
