/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 19:52:44 by yacinebenta       #+#    #+#             */
/*   Updated: 2021/11/02 12:30:07 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_putstr_fd(char *s, int fd);
int	ft_putchar_fd(char c, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_deca_hexa(unsigned long dec);
int	check_neg_hexa(int n);
int	ft_deca_hexa_min(unsigned long dec);
int	ft_printf(const char *str, ...);
int check_exeption_hexa(unsigned long n);
int	ptr_hexa(unsigned long n);

#endif
