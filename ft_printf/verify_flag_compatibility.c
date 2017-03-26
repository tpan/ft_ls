/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_flag_compatibility.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 12:29:03 by tpan              #+#    #+#             */
/*   Updated: 2017/03/18 19:00:20 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			hashtag_compatibility(t_conversion *conversion)
{
	if (conversion->flags.hash)
		if (!(conversion->specifier == HEX_LOWER ||
				conversion->specifier == HEX_UPPER ||
				conversion->specifier == OCTAL))
			return (INVALID);
	return (VALID);
}

static int			zero_flag(t_conversion *conversion)
{
	if (conversion->flags.pad_zeros)
		if (conversion->specifier == CHAR
			|| conversion->specifier == STRING
			|| conversion->specifier == POINTER)
			return (INVALID);
	return (VALID);
}

static int			show_positive_flag(t_conversion *conversion)
{
	if (conversion->flags.pos_values_append_space
			|| conversion->flags.show_sign)
		if (conversion->specifier == U_DECIMAL
		|| conversion->specifier == CHAR)
		{
			conversion->flags.pos_values_append_space = 0;
			conversion->flags.show_sign = 0;
		}
	return (VALID);
}

int					verify_flag_compatibility(t_conversion *conversion)
{
	if (hashtag_compatibility(conversion) == INVALID)
		return (INVALID);
	if (zero_flag(conversion) == INVALID)
		return (INVALID);
	if (show_positive_flag(conversion) == INVALID)
		return (INVALID);
	return (VALID);
}
