/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:26:19 by jmehlig           #+#    #+#             */
/*   Updated: 2021/07/02 15:20:00 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	if (src == NULL)
		return (0);
	srclen = ft_strlen(src);
	if (srclen + 1 < dstsize)
		dst = (char *)ft_memcpy(dst, src, srclen + 1);
	else if (dstsize != 0)
	{
		dst = (char *)ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (srclen);
}
