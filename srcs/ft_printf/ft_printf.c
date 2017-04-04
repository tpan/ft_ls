/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 16:38:23 by tpan              #+#    #+#             */
/*   Updated: 2017/02/02 16:42:54 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			chars_printed;

	if (!format)
		return (0);
	va_start(ap, format);
	chars_printed = ft_vprintf(format, ap);
	va_end(ap);
	return (chars_printed);
}
