/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:33:37 by lsaumon           #+#    #+#             */
/*   Updated: 2024/03/09 02:54:50 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_printf_formats(va_list args, const char formats)
{
	int	printlen;

	printlen = 0;
	if (formats == 'c')
		printlen += ft_printchar(va_arg(args, int));
	else if (formats == 's')
		printlen += ft_printstr(va_arg(args, char *));
	else if (formats == 'p')
		printlen += ft_printptr(va_arg(args, unsigned long), formats);
	else if (formats == 'd' || formats == 'i')
		printlen += ft_printnbr(va_arg(args, int), formats);
	else if (formats == 'u')
		printlen += ft_printnbr(va_arg(args, unsigned int), formats);
	else if (formats == 'x' || formats == 'X')
		printlen += ft_printnbr(va_arg(args, unsigned int), formats);
	else if (formats == '%')
		printlen += ft_printpercent();
	return (printlen);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	size_t	l;

	va_start(args, str);
	i = 0;
	l = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
				return (-1);
			l += ft_printf_formats(args, str[i + 1]);
			i += 2;
		}
		else
		{
			l += ft_printchar(str[i]);
			i++;
		}
	}
	va_end(args);
	return (l);
}
