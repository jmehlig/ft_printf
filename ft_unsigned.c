/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:17:22 by jmehlig           #+#    #+#             */
/*   Updated: 2021/09/09 12:17:36 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//used for creating a hex string out of a given int
char	*int_base_str(unsigned int i, unsigned int base, long	power, int j)
{
	int		k;
	long	frac;
	char	*i_str;

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

//takes an unsigned int and a base and converts it into the corresponding system, returns it as a string
//used to convert int to hex
char	*int_tobase(unsigned int i, unsigned int base)
{
	unsigned int	frac;
	long			power;
	int				j;

	frac = i;
	power = 1;
	j = 0;
	while (frac >= base)
	{
		frac = frac / base;
		power = power * base;
		j++;
	}
	return (int_base_str(i, base, power, j));
}

//handles %u - actually prints the unsigned int
void	ft_putunsigned_fd(unsigned int n)
{
	if (n == 4294967295)
		ft_putstr_fd("4294967295", 1);
	else
	{
		if (n > 9)
		{
			ft_putunsigned_fd((n / 10));
		}
		ft_putchar_fd((char)((n % 10) + '0'), 1);
	}
}
