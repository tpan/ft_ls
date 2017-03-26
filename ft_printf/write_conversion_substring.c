/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_conversion_substring.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 13:26:50 by tpan              #+#    #+#             */
/*   Updated: 2017/03/20 17:44:49 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		write_conversion_substring(t_conversion *conversion, va_list ap,
										t_format *format)
{
	if (conversion->specifier == S_DECIMAL)
		write_signed_int(conversion, ap, format);
	if (conversion->specifier == U_DECIMAL)
		write_unsigned_int(conversion, ap, format);
	if (conversion->specifier == HEX_UPPER
			|| conversion->specifier == HEX_LOWER
			|| conversion->specifier == POINTER)
		write_hex(conversion, ap, format);
	if (conversion->specifier == OCTAL)
		write_octal(conversion, ap, format);
	if (conversion->specifier == STRING && conversion->length >= L)
		write_wstring(conversion, ap, format);
	else if (conversion->specifier == STRING)
		write_string(conversion, ap, format);
	if (conversion->specifier == CHAR && conversion->length >= L
											&& MB_CUR_MAX > 1)
		write_wchar(conversion, ap, format);
	else if (conversion->specifier == CHAR)
		write_chars(conversion, ap, format);
	return ;
}
