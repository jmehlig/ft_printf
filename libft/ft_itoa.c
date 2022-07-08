/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:15:32 by jmehlig           #+#    #+#             */
/*   Updated: 2021/07/02 15:18:14 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_size(int n)
{
	int	size;

	size = 1;
	while (n > 9)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static char	*n_str(char *str, int i, int n, int sgn_space)
{
	if (sgn_space == 1)
	{
		*(str + i) = '-';
		i++;
	}
	i = i + n_size(n);
	*(str + i) = '\0';
	i--;
	while (i >= sgn_space)
	{
		*(str + i) = (char)((n % 10) + '0');
		n = n / 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		sgn_space;

	i = 0;
	sgn_space = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		sgn_space = 1;
		n = -n;
	}
	str = (char *)malloc(sizeof(char) * (n_size(n) + sgn_space + 1));
	if (!str)
		return (0);
	str = n_str(str, i, n, sgn_space);
	return (str);
}
