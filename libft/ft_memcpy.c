/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:33:54 by jmehlig           #+#    #+#             */
/*   Updated: 2021/07/02 15:18:54 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *target, const void *source, size_t size)
{
	char	*elements;
	char	*elementt;
	char	*begin;

	begin = target;
	if (target == NULL && source == NULL)
		return (NULL);
	while (size > 0)
	{
		elements = (char *)source;
		elementt = target;
		*elementt = *elements;
		target++;
		source++;
		size--;
	}
	return (begin);
}
