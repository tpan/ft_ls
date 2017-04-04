/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 12:13:06 by tpan              #+#    #+#             */
/*   Updated: 2017/03/20 17:39:39 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_specifier	compare_specifiers(char c)
{
	if (c == 'd' || c == 'i' || c == 'D')
		return (S_DECIMAL);
	if (c == 'u' || c == 'U')
		return (U_DECIMAL);
	if (c == 'o' || c == 'O')
		return (OCTAL);
	if (c == 'x')
		return (HEX_LOWER);
	if (c == 'X')
		return (HEX_UPPER);
	if (c == 'c' || c == 'C')
		return (CHAR);
	if (c == 's' || c == 'S')
		return (STRING);
	if (c == 'p')
		return (POINTER);
	if (c == 'n')
		return (CHARS_WRITTEN);
	return (INVALID_SPECIFIER);
}

int					read_specifier(t_conversion *conversion, t_format *format)
{
	char	c;

	if (!format->str[format->index])
		return (INVALID);
	c = format->str[format->index];
	conversion->specifier = compare_specifiers(format->str[format->index]);
	if (conversion->specifier == INVALID_SPECIFIER)
		return (INVALID);
	if (c == 'D' || c == 'U' || c == 'O' || c == 'C' || c == 'S')
		conversion->length = L;
	format->index++;
	return (VALID);
}
