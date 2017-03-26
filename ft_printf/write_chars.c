/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 12:20:05 by tpan              #+#    #+#             */
/*   Updated: 2017/03/20 17:44:21 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	print_null(t_conversion *conversion, t_format *format,
							char *draft)
{
	ft_putchar('\0');
	format->chars_written++;
	if (ft_strlen(draft) + 1 < conversion->width)
	{
		ft_putstr(&draft[ft_strlen(draft) + 2]);
		format->chars_written += ft_strlen(&draft[ft_strlen(draft) + 2]);
	}
}

void			write_chars(t_conversion *conversion, va_list ap,
						t_format *format)
{
	char	c;
	char	*draft;

	if (conversion->flags.hash)
		return ;
	c = va_arg(ap, int);
	draft = ft_strnew(1);
	*draft = c;
	if (!conversion->width && conversion->flags.pos_values_append_space)
	{
		ft_putchar(' ');
		format->chars_written++;
	}
	apply_width(conversion, &draft);
	ft_putstr(draft);
	format->chars_written += ft_strlen(draft);
	if (c == '\0')
		print_null(conversion, format, draft);
	ft_memdel((void **)&draft);
}

void			write_string(t_conversion *conversion, va_list ap,
				t_format *format)
{
	char	*draft;

	draft = va_arg(ap, char *);
	if (draft)
		draft = ft_strdup(draft);
	else
		draft = ft_strdup("(null)");
	if (conversion->precision_set)
		apply_precision(conversion, &draft);
	if (conversion->width)
		apply_width(conversion, &draft);
	ft_putstr(draft);
	format->chars_written += ft_strlen(draft);
	ft_memdel((void **)&draft);
	return ;
}
