/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:14:48 by jmehlig           #+#    #+#             */
/*   Updated: 2021/07/02 15:18:58 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *target, const void *source, size_t size)
{
	char	*tar;
	char	*src;

	if (target == NULL && source == NULL)
		return (NULL);
	if (target < source)
		target = (char *)ft_memcpy(target, source, size);
	else
	{
		tar = (char *)target + (size - 1);
		src = (char *)source + (size - 1);
		while (size > 0)
		{
			*tar = *src;
			tar--;
			src--;
			size--;
		}
	}
	return (target);
}
