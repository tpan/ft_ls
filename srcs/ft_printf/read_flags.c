/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 13:27:25 by tpan              #+#    #+#             */
/*   Updated: 2017/02/08 10:31:31 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_flag(char c, t_flags *flags)
{
	if (c == '#')
		return (flags->hash = 1);
	if (c == ' ')
		return (flags->pos_values_append_space = 1);
	if (c == '+')
		return (flags->show_sign = 1);
	if (c == '-')
		return (flags->left_justify = 1);
	if (c == '0')
		return (flags->pad_zeros = 1);
	return (0);
}

int			read_flags(t_conversion *conversion, t_format *format)
{
	char	c;

	while ((c = format->str[format->index])
				&& check_flag(c, &conversion->flags))
		format->index++;
	return (VALID);
}
