/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:46:49 by jmehlig           #+#    #+#             */
/*   Updated: 2021/07/02 15:19:56 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dest;
	size_t	len_src;
	int		i;

	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	if (dstsize == 0 || dstsize <= len_dest)
		return (dstsize + len_src);
	while (src[i] && (i + len_dest + 1) < dstsize)
	{
		dst[len_dest + i] = src[i];
		i++;
	}
	dst[len_dest + i] = '\0';
	if (len_dest < dstsize)
		return (len_dest + len_src);
	return (dstsize + len_src);
}
