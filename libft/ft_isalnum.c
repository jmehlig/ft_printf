/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:28:46 by jmehlig           #+#    #+#             */
/*   Updated: 2021/07/02 15:17:29 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int argument)
{
	if ((argument >= 'a') && (argument <= 'z'))
		return (1);
	else if ((argument >= 'A') && (argument <= 'Z'))
		return (1);
	else if ((argument >= '0') && (argument <= '9'))
		return (1);
	else
		return (0);
}
