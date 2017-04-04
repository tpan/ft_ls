/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:07:06 by tpan              #+#    #+#             */
/*   Updated: 2017/03/20 17:41:55 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		read_width(t_conversion *conversion, va_list ap,
		t_format *format)
{
	int holder;

	if (format->str[format->index] == '*')
	{
		holder = va_arg(ap, int);
		if (holder < 0)
		{
			holder = -holder;
			conversion->flags.left_justify = 21;
		}
		conversion->width = holder;
		format->index++;
	}
	else if (ft_isdigit(format->str[format->index]))
	{
		conversion->width = ft_atoi(&format->str[format->index]);
		while (ft_isdigit(format->str[format->index]))
			format->index++;
	}
	return (VALID);
}
