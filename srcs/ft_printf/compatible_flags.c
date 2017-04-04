/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compatible_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 20:01:33 by tpan              #+#    #+#             */
/*   Updated: 2017/03/20 17:14:15 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			pos_values_append_space_corr(t_conversion *conversion)
{
	if (conversion->flags.pos_values_append_space
			&& conversion->flags.show_sign)
		conversion->flags.pos_values_append_space = 0;
	return ;
}

static void			pad_zeros_corr(t_conversion *conversion)
{
	if (conversion->flags.pad_zeros)
		if (conversion->flags.left_justify || conversion->precision_set)
			conversion->flags.pad_zeros = 0;
	return ;
}

static int			precision_is_settable(t_conversion *conversion)
{
	if (conversion->precision_set)
		if ((conversion->specifier == CHAR && conversion->length >= L)
				|| conversion->specifier == POINTER)
			conversion->precision_set = 0;
	return (VALID);
}

static int			pointer_size_specified(t_conversion *conversion)
{
	if (conversion->specifier == POINTER && conversion->length != DEFAULT)
		return (INVALID);
	return (VALID);
}

int					compatible_flags(t_conversion *conversion,
t_format *format)
{
	format->index--;
	pos_values_append_space_corr(conversion);
	pad_zeros_corr(conversion);
	if (precision_is_settable(conversion) == INVALID)
		return (INVALID);
	if (pointer_size_specified(conversion) == INVALID)
		return (INVALID);
	if (verify_flag_compatibility(conversion) == INVALID)
		return (INVALID);
	format->index++;
	return (VALID);
}
