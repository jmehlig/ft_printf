/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 13:00:13 by jmehlig           #+#    #+#             */
/*   Updated: 2021/07/02 15:20:23 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*save;
	size_t		count;

	if (*needle == '\0')
		return ((char *)haystack);
	while (len > 0 && *haystack != '\0')
	{
		save = haystack;
		count = 0;
		while (count < len && *haystack && needle[count]
			&& needle[count] == *haystack)
		{
			haystack++;
			count++;
		}
		if (needle[count] == '\0')
			return ((char *)save);
		len--;
		haystack = save + 1;
	}
	return (NULL);
}
