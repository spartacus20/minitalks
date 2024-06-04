/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:59:57 by jotomas-          #+#    #+#             */
/*   Updated: 2024/01/05 11:33:30 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"
#include "unistd.h"

// Handle Formats.
int	handle_formats(char format, va_list args)
{
	int	count;

	count = 0;
	if (format == '%')
		count += ft_print_char('%');
	else if (format == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (format == 'd' || format == 'i')
		count += ft_print_number(va_arg(args, int));
	else if (format == 'u')
		count += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 's')
		count += ft_print_string(va_arg(args, char *));
	else if (format == 'p')
		count += ft_print_ptr((unsigned long int)va_arg(args, void *));
	else if (format == 'x' || format == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), format);
	return (count);
}

int	ft_printf(char const *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			count += handle_formats(*(format + 1), args);
			format++;
		}
		else
		{
			count += ft_print_char(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}
