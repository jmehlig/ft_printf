/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:17:54 by jmehlig           #+#    #+#             */
/*   Updated: 2021/09/09 12:18:07 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(void *ptr)
{
	unsigned long long	ptr_nbr;
	char				*ptr_hex;
	int					length;

	if (ptr == (void *) -1)
	{
		write(1, &"0xffffffffffffffff", 18);
		length = 18;
	}
	else
	{
		ptr_nbr = (unsigned long long) ptr;
		ptr_hex = tobase(ptr_nbr, 16);
		write(1, &"0x", 2);
		ft_putstr_fd(ptr_hex, 1);
		length = ft_strlen((const char *) ptr_hex) + 2;
		free(ptr_hex);
	}
	return (length);
}

char	ft_write(int k)
{
	char	c;

	if (k >= 0 && k < 10)
		c = k + '0';
	else
		c = k + 87;
	return (c);
}

char	*base_str(unsigned long long i, int base, long long	power, int j)
{
	int			k;
	long long	frac;
	char		*i_str;

	i_str = (char *)malloc(j + 2);
	if (!i_str)
		return (NULL);
	j = 0;
	while (power != 1)
	{
		frac = i - power;
		k = 0;
		while (frac >= 0)
		{
			k++;
			i = frac;
			frac = i - power;
		}
		power = power / base;
		i_str[j] = ft_write(k);
		j++;
	}
	i_str[j] = ft_write(i);
	i_str[j + 1] = '\0';
	return (i_str);
}

char	*tobase(unsigned long long i, int base)
{
	unsigned long long	frac;
	long long			power;
	int					j;

	frac = i;
	power = 1;
	j = 0;
	while (frac >= (unsigned long long)base)
	{
		frac = frac / base;
		power = power * base;
		j++;
	}
	return (base_str(i, base, power, j));
}
