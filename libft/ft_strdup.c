/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:13:55 by jmehlig           #+#    #+#             */
/*   Updated: 2021/07/02 15:19:46 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	void	*ptr;
	char	*save;
	size_t	len;

	len = ft_strlen(s1);
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	save = (char *)ptr;
	while (*s1 != '\0')
	{
		*(char *)ptr = *s1;
		ptr++;
		s1++;
	}
	*(char *)ptr = '\0';
	return (save);
}
