/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 20:07:25 by jmehlig           #+#    #+#             */
/*   Updated: 2021/07/02 17:17:30 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*save;

	if (lst == NULL)
		return ;
	while ((**lst).next != NULL)
	{
		save = (**lst).next;
		ft_lstdelone(*lst, del);
		(*lst) = save;
	}
	ft_lstdelone(*lst, del);
	*lst = NULL;
}
