/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 11:32:54 by jmehlig           #+#    #+#             */
/*   Updated: 2021/09/09 12:54:00 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_flags
{
	int	space;
	int	width;
	int	minus;
	int	zero;
	int	dot;
	int	hash;
	int	plus;
	int	prec;
	int	save;
	int	tempi;
	int	tempcp;
}		t_flags;

int		print_char(char c);
int		print_string(va_list arglist);
int		print_ptr(void *ptr);
int		print_deci(int i);
int		print_hexa(int i, char c);
int		print_unsigned(unsigned int i);
int		print_cases(char c, va_list arglist);
int		get_printed(char *temp, va_list arglist);
int		ft_printf(const char *input, ...);
char	ft_write(int k);
char	*base_str(unsigned long long i, int base, long long	power, int j);
char	*tobase(unsigned long long i, int base);
void	ft_putunsigned_fd(unsigned int n);
char	*int_base_str(unsigned int i, unsigned int base, long	power, int j);
char	*int_tobase(unsigned int i, unsigned int base);

#endif
