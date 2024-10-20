/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:34:03 by lsaumon           #+#    #+#             */
/*   Updated: 2024/10/21 01:00:46 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
int		ft_printf_formats(va_list args, const char formats);

size_t	ft_printchar(char c);
size_t	ft_printptr(unsigned long ptr, char type);
size_t	ft_pstrlen(const char *s);
size_t	ft_printstr(char *s);
size_t	ft_printpercent(void);
size_t	ft_printnbr(long nb, char type);

#endif
