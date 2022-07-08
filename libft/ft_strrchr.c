/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 12:10:13 by jmehlig           #+#    #+#             */
/*   Updated: 2021/07/26 14:33:17 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*save;
	int		change;

	ptr = (char *)s;
	change = 0;
	while (*ptr != '\0')
	{
		if (*ptr == (unsigned char)c)
		{
			save = ptr;
			change = 1;
		}
		ptr++;
	}
	if (c == '\0')
		return (ptr);
	if (change == 0)
		return (NULL);
	return (save);
}
