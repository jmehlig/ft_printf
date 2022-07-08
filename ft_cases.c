/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:16:43 by jmehlig           #+#    #+#             */
/*   Updated: 2021/09/09 12:16:59 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_string(va_list arglist)
{
	char	*temp;

	temp = va_arg(arglist, char *);
	if (temp != NULL)
	{
		ft_putstr_fd(temp, 1);
		return (ft_strlen(temp));
	}
	else
	{
		write(1, &"(null)", 6);
		return (6);
	}
}

int	print_deci(int i)
{
	int	size;
	int	sign_space;

	ft_putnbr_fd(i, 1);
	size = 1;
	sign_space = 0;
	if (i == -2147483648)
		return (11);
	if (i < 0)
	{
		sign_space = 1;
		i = -i;
	}
	while (i > 9)
	{
		i = i / 10;
		size++;
	}
	return (size + sign_space);
}

int	print_hexa(int i, char c)
{
	char	*i_hex;
	int		j;
	int		length;

	i_hex = int_tobase(i, 16);
	j = 0;
	if (c == 'X')
	{
		while (i_hex[j] != '\0')
		{
			i_hex[j] = ft_toupper(i_hex[j]);
			j++;
		}
	}
	ft_putstr_fd(i_hex, 1);
	length = ft_strlen((const char *)i_hex);
	free(i_hex);
	return (length);
}

int	print_unsigned(unsigned int i)
{
	int	size;

	ft_putunsigned_fd(i);
	size = 1;
	while (i > 9)
	{
		i = i / 10;
		size++;
	}
	return (size);
}
