/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:29:11 by jmehlig           #+#    #+#             */
/*   Updated: 2021/08/03 09:20:24 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_number(const char *str, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i + 1] == c || str[i + 1] == '\0')
			&& (str[i] != c && str[i] != '\0'))
			words++;
		i++;
	}
	return (words);
}

static void	write_word(char *dest, const char *src, char c)
{
	while (*src != c && *src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

static int	write_split(char **split, const char *str, char c)
{
	int	i;
	int	inword_count;
	int	word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c || str[i] == '\0')
			i++;
		else
		{
			inword_count = 0;
			while ((str[i + inword_count] != c
					&& str[i + inword_count] != '\0'))
				inword_count++;
			split[word] = (char *)malloc(sizeof(char) * (inword_count + 1));
			if (!split)
				return (-1);
			write_word(split[word], str + i, c);
			i = i + inword_count;
			word++;
		}
	}
	return (0);
}

char	**ft_split(const char *str, char c)
{
	char	**res;
	int		words;

	if (str == NULL)
		return (NULL);
	words = word_number(str, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	res[words] = 0;
	if (write_split(res, str, c) == -1)
		return (NULL);
	return (res);
}
