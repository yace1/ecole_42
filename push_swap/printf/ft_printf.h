/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 19:52:44 by yacinebenta       #+#    #+#             */
/*   Updated: 2021/12/02 12:17:33 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

int		ft_deca_hexa(unsigned long dec);
int		check_neg_hexa(int n);
void	ft_deca_hexa_min(unsigned long dec, int *i);
int		ft_printf(const char *str, ...);
int		check_exeption_hexa(unsigned long n);
int		ptr_hexa(unsigned long n);
int		ft_putuint(unsigned int n, int fd);
int		ft_putstr_fd2(char *s, int fd);
int		ft_putchar_fd2(char c, int fd);
int		ft_putnbr_fd2(int n, int fd);

#endif
