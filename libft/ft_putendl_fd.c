/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 20:08:41 by jmehlig           #+#    #+#             */
/*   Updated: 2021/07/02 15:19:17 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	line[2];

	if (s == NULL)
		return ;
	line[0] = '\n';
	while (*s != '\0')
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
	write(fd, (const void *)line, sizeof(char));
}
