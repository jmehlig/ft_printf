/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:18:10 by jmehlig           #+#    #+#             */
/*   Updated: 2021/06/30 20:13:40 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] != 0 && ft_strchr(set, s1[i]) != NULL)
		i++;
	return (i);
}

static size_t	ft_end(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	while (i < len && ft_strchr(set, s1[len - 1 - i]))
		i++;
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	str_start;
	size_t	str_end;
	char	*res;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	str_start = ft_start(s1, set);
	str_end = ft_end(s1, set);
	if (str_start >= str_end)
	{
		res = (char *)malloc(sizeof(char));
		*res = '\0';
		return (res);
	}
	res = (char *)malloc(sizeof(char) * (str_end - str_start + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1 + str_start, str_end - str_start + 1);
	return (res);
}
