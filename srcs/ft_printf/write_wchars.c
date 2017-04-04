/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_wchars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:43:08 by tpan              #+#    #+#             */
/*   Updated: 2017/03/20 19:30:19 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			cleanup_memory(wchar_t **draft, char **utf8_draft)
{
	ft_memdel((void **)draft);
	ft_memdel((void **)utf8_draft);
}

static void			print_null_wchar(t_conversion *conversion, t_format *format,
		wchar_t *draft)
{
	char		*utf8_draft_post_null;

	utf8_draft_post_null = ft_utf8strencode(draft + ft_wstrlen(draft) + 1);
	ft_putchar('\0');
	format->chars_written++;
	if (ft_wstrlen(draft) + 1 < conversion->width)
	{
		ft_putstr(utf8_draft_post_null);
		format->chars_written += ft_strlen((char *)&utf8_draft_post_null);
	}
	ft_memdel((void **)&utf8_draft_post_null);
}

void				write_wchar(t_conversion *conversion, va_list ap,
		t_format *format)
{
	wchar_t		*draft;
	char		*utf8_draft;

	if (conversion->flags.hash)
		return ;
	else
	{
		draft = (wchar_t *)malloc(sizeof(wchar_t) * 2);
		*draft = va_arg(ap, wint_t);
		draft[1] = '\0';
		if (!conversion->width & conversion->flags.pos_values_append_space)
		{
			ft_putchar(' ');
			format->chars_written++;
		}
		apply_width_wchar(conversion, &draft);
		utf8_draft = ft_utf8strencode(draft);
		ft_putstr(utf8_draft);
		format->chars_written += ft_strlen(utf8_draft);
		if (*draft == '\0')
			print_null_wchar(conversion, format, draft);
		cleanup_memory(&draft, &utf8_draft);
	}
}

void				write_wstring(t_conversion *conversion, va_list ap,
		t_format *format)
{
	wchar_t			*draft;
	t_utf8			*utf8draft;

	draft = ft_wstrdup(va_arg(ap, wchar_t *));
	if (!draft)
		draft = ft_wstrdup(L"(null)");
	if (conversion->precision_set)
		apply_precision_wstr(conversion, &draft);
	if (conversion->width)
		apply_width_wchar(conversion, &draft);
	utf8draft = ft_utf8strencode(draft);
	ft_putstr(utf8draft);
	format->chars_written += ft_strlen((char *)utf8draft);
	ft_memdel((void **)&draft);
	ft_memdel((void **)&utf8draft);
	return ;
}
