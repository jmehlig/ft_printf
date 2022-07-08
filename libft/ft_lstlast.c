/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 20:05:47 by jmehlig           #+#    #+#             */
/*   Updated: 2021/07/02 15:18:29 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (lst);
	while ((*lst).next != NULL)
	{
		lst = (*lst).next;
	}
	if ((*lst).next == NULL)
		return (lst);
	return (NULL);
}
