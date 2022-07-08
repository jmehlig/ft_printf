/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 20:08:27 by jmehlig           #+#    #+#             */
/*   Updated: 2021/08/19 11:48:31 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list_item;
	t_list	*newlist;

	newlist = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		new_list_item = ft_lstnew(f(lst->content));
		if (!new_list_item)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		if (!newlist)
			newlist = new_list_item;
		else
			ft_lstadd_back(&newlist, new_list_item);
		lst = lst->next;
	}
	return (newlist);
}
