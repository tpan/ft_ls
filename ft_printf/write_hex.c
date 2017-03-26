/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 13:43:40 by tpan              #+#    #+#             */
/*   Updated: 2017/03/20 17:49:42 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Apply precision, then prefix, then width and justification.
*/

static void		prefix_hex(t_conversion *conversion, char **draft)
{
	char	*temp;
	int		i;

	i = ft_ishex(*(*draft + 1)) && !ft_ishex(**draft) ? 1 : 2;
	temp = *draft;
	*draft = ft_strnew(ft_strlen(*draft) + i);
	**draft = '0';
	*(*draft + 1) = 'X';
	ft_strncpy(*draft + 2, temp,
	conversion->width ? conversion->width - i : ft_strlen(temp));
	ft_memdel((void **)&temp);
	return ;
}

static void		add_hex_prefix(t_conversion *conversion, char **draft)
{
	int i;

	if (**draft == '0' && (*draft)[1] == '0')
		(*draft)[1] = 'X';
	else if ((ft_ishex(**draft) || ft_ishex(*(*draft + 1))))
		prefix_hex(conversion, draft);
	else
	{
		i = 0;
		while (!ft_ishex((*draft)[i]) || (*draft)[i] == '0')
			if ((*draft)[i++] == '\0')
				return ;
		i -= 2;
		(*draft)[i] = '0';
		(*draft)[++i] = 'X';
	}
}

void			write_hex(t_conversion *conversion, va_list ap,
		t_format *format)
{
	char		*draft;
	uintmax_t	value;

	value = get_unsigned_int_arg(conversion, ap);
	if (!value && conversion->precision_set)
		draft = ft_strdup("");
	else
		draft = ft_itoa_base_uintmax(value, 16);
	if (conversion->precision_set && conversion->specifier != POINTER)
		apply_precision(conversion, &draft);
	if (conversion->width)
		apply_width(conversion, &draft);
	if (conversion->flags.pos_values_append_space
			|| conversion->flags.show_sign)
		apply_prefix(conversion, &draft);
	if ((conversion->flags.hash && value)
			|| conversion->specifier == POINTER)
		add_hex_prefix(conversion, &draft);
	if (conversion->specifier == HEX_LOWER || conversion->specifier == POINTER)
		ft_tolower_str(draft);
	ft_putstr(draft);
	format->chars_written += ft_strlen(draft);
	ft_memdel((void **)&draft);
}
