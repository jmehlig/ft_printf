/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:25:50 by jmehlig           #+#    #+#             */
/*   Updated: 2021/08/03 09:24:13 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t size)
{
	unsigned char	*pos;

	while (size > 0)
	{
		pos = (unsigned char *)str;
		if (*pos == (unsigned char)c)
		{
			return (pos);
		}
		str++;
		size--;
	}
	return (0);
}
