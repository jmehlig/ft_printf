/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 20:06:11 by jmehlig           #+#    #+#             */
/*   Updated: 2021/07/02 17:16:44 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*back;

	if (lst != NULL)
	{
		if (*lst != NULL)
		{
			back = ft_lstlast(*lst);
			(*back).next = new;
		}
		else
			*lst = new;
	}
}
