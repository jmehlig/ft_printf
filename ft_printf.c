/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:16:07 by jmehlig           #+#    #+#             */
/*   Updated: 2021/09/09 12:16:20 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//looking which conversion is asked for and actually redirecting it to the function handeling the needed case
//returns the characters printed while doing the conversion
int	print_cases(char c, va_list arglist)
{
	int		char_printed;

	char_printed = 0;
	if (c == 'c')
		char_printed = print_char((char)va_arg(arglist, int));
	else if (c == 's')
		char_printed = print_string(arglist);
	else if (c == 'p')
		char_printed = print_ptr(va_arg(arglist, void *));
	else if (c == 'd' || c == 'i')
		char_printed = print_deci(va_arg(arglist, int));
	else if (c == 'u')
		char_printed = print_unsigned((int)va_arg(arglist, unsigned int));
	else if (c == 'x' || c == 'X')
		char_printed = print_hexa(va_arg(arglist, int), c);
	else if (c == '%')
	{
		write(1, &"%%", 1);
		char_printed = 1;
	}
	return (char_printed);
}

//counts the amount of characters printed
//redirects if the charcter '%' is found in the input string
//other characters get printed directly
int	get_printed(char *temp, va_list arglist)
{
	int	i;
	int	char_printed;

	i = 0;
	char_printed = 0;
	while (temp[i] != '\0')
	{
		if (temp[i] != '%' && temp[i] != '\0')
		{
			ft_putchar_fd(temp[i], 1);
			char_printed++;
			i++;
		}
		else
		{
			i++;
			if (ft_strchr("cspdiuxX%", temp[i]))
			{
				char_printed = char_printed + print_cases(temp[i], arglist);
				i++;
			}
		}
	}
	return (char_printed);
}

// mimics the printf function, returns the amount of characters printed
//variadic function ,therefore uses va_list for reading the optional input
int	ft_printf(const char *input, ...)
{
	va_list	arglist;
	int		char_printed;

	va_start(arglist, input);
	char_printed = get_printed((char *)input, arglist);
	va_end(arglist);
	return (char_printed);
}
