/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:38:17 by jmehlig           #+#    #+#             */
/*   Updated: 2021/08/10 17:46:48 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	char	*begin;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (start > 0 && *s != '\0')
	{
		start--;
		s++;
	}
	begin = ptr;
	while (len > 0 && *s != '\0')
	{
		*ptr = *s;
		ptr++;
		s++;
		len--;
	}
	*ptr = '\0';
	return (begin);
}
