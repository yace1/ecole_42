/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:42:07 by ybentaye          #+#    #+#             */
/*   Updated: 2021/10/13 13:27:44 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*ptr;
	int				i;
	unsigned int	total;

	i = 0;
	total = count * size;
	if(total == 0)
		return (0);

	ptr = malloc(count * size);
	while (total > 0)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
