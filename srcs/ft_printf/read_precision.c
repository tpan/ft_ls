/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 11:41:37 by tpan              #+#    #+#             */
/*   Updated: 2017/03/20 17:37:50 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		treat_negative_precision_as_none(t_conversion *conversion,
												t_format *format)
{
	conversion->precision = 0;
	format->index++;
	while (ft_isdigit(format->str[format->index]))
		format->index++;
	return (VALID);
}

static int		wildcard_precision(t_conversion *conversion, va_list ap,
		t_format *format)
{
	int		tmp;

	tmp = va_arg(ap, int);
	format->index++;
	if (tmp < 0)
		conversion->precision_set = 0;
	else
		conversion->precision = tmp;
	return (VALID);
}

int				read_precision(t_conversion *conversion, va_list ap,
												t_format *format)
{
	if (format->str[format->index] == '.')
	{
		format->index++;
		if (format->str[format->index] == '-')
			return (treat_negative_precision_as_none(conversion, format));
		conversion->precision_set = 1;
		if (format->str[format->index] == '*')
			return (wildcard_precision(conversion, ap, format));
		if (ft_isdigit(format->str[format->index]))
		{
			conversion->precision = ft_atoi(&format->str[format->index]);
			while (ft_isdigit(format->str[format->index]))
				format->index++;
			return (VALID);
		}
	}
	return (VALID);
}
