/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 20:08:00 by jmehlig           #+#    #+#             */
/*   Updated: 2021/07/02 17:17:25 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*iter;

	if (lst != NULL)
	{
		iter = lst;
		while (iter != NULL)
		{
			(*f)((*iter).content);
			iter = (*iter).next;
		}
	}
}
