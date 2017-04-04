/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:44:17 by tpan              #+#    #+#             */
/*   Updated: 2017/03/20 19:27:43 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t		get_unsigned_int_arg(t_conversion *conversion, va_list ap)
{
	uintmax_t	nbr;

	if (conversion->specifier == POINTER)
	{
		nbr = (uintmax_t)va_arg(ap, void *);
		return (nbr);
	}
	if (conversion->length == HH)
		nbr = (unsigned char)va_arg(ap, int);
	if (conversion->length == H)
		nbr = (unsigned short int)va_arg(ap, unsigned int);
	if (conversion->length == DEFAULT)
		nbr = va_arg(ap, unsigned int);
	if (conversion->length == LL)
		nbr = va_arg(ap, unsigned long long);
	if (conversion->length == L)
		nbr = va_arg(ap, unsigned long);
	if (conversion->length == J)
		nbr = va_arg(ap, uintmax_t);
	if (conversion->length == Z)
		nbr = va_arg(ap, size_t);
	return (nbr);
}

void			write_unsigned_int(t_conversion *conversion, va_list ap,
		t_format *format)
{
	uintmax_t	nbr;
	char		*draft;

	nbr = get_unsigned_int_arg(conversion, ap);
	if (!nbr && conversion->precision_set)
		draft = ft_strdup("");
	else
		draft = ft_itoa_base_uintmax(nbr, 10);
	if (conversion->precision_set)
		apply_precision(conversion, &draft);
	if (conversion->width)
		apply_width(conversion, &draft);
	if (conversion->flags.pos_values_append_space
			|| conversion->flags.show_sign)
		apply_prefix(conversion, &draft);
	ft_putstr(draft);
	format->chars_written += ft_strlen(draft);
	ft_memdel((void **)&draft);
	return ;
}
