/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:39:21 by jmehlig           #+#    #+#             */
/*   Updated: 2021/07/02 15:18:49 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t size)
{
	unsigned char	*pos1;
	unsigned char	*pos2;
	int				i;

	pos1 = (unsigned char *)str1;
	pos2 = (unsigned char *)str2;
	i = 0;
	while (size > 0)
	{
		if (pos1[i] != pos2[i])
		{
			return (pos1[i] - pos2[i]);
		}
		i++;
		size--;
	}
	if (size != 0 && pos2[i] != '\0')
		return (-(pos2[i]));
	return (0);
}
