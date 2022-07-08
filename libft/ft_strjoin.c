/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:05:10 by jmehlig           #+#    #+#             */
/*   Updated: 2021/07/02 16:12:08 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	char	*ptr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	joined = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joined)
		return (NULL);
	ptr = joined;
	while (*s1 != '\0')
	{
		*ptr = *s1;
		s1++;
		ptr++;
	}
	while (*s2 != '\0')
	{
		*ptr = *s2;
		s2++;
		ptr++;
	}
	*ptr = '\0';
	return (joined);
}
