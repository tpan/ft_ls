/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 10:32:13 by tpan              #+#    #+#             */
/*   Updated: 2017/03/20 17:10:21 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			apply_precision_str(t_conversion *conversion, char **draft)
{
	char	*temp;

	if (conversion->precision < ft_strlen(*draft))
	{
		temp = *draft;
		*draft = ft_strndup(*draft, conversion->precision);
		ft_memdel((void **)&temp);
	}
	return ;
}

/*
** Ints and hex values are padded with appended zeroes if the precision is
** longer than the number of digits needed to display the number, but a
** smaller precision will never truncate the number.
*/

static void			apply_precision_int(t_conversion *conversion, char **draft)
{
	char	*temp;
	size_t	i;

	if (ft_strlen(*draft) < conversion->precision + conversion->int_negative)
	{
		temp = *draft;
		*draft = ft_strnew(conversion->precision + 1 +
				conversion->int_negative);
		(*draft)[conversion->precision + conversion->int_negative] = '\0';
		i = 0;
		if (conversion->int_negative)
			(*draft)[i++] = '-';
		while (i - conversion->int_negative
		< conversion->precision - ft_strlen(temp) + conversion->int_negative)
			(*draft)[i++] = '0';
		ft_strcpy(&((*draft)[i]), temp + conversion->int_negative);
		ft_memdel((void **)&temp);
	}
	return ;
}

void				apply_precision_wstr(t_conversion *conversion,
															wchar_t **draft)
{
	wchar_t	*temp;

	if (conversion->precision < ft_wstrlen(*draft))
	{
		temp = *draft;
		*draft = ft_wstrndup(*draft, conversion->precision);
		ft_memdel((void **)&temp);
	}
	return ;
}

void				apply_precision(t_conversion *conversion, char **draft)
{
	if (conversion->specifier == STRING)
		apply_precision_str(conversion, draft);
	else if (conversion->specifier != POINTER)
		apply_precision_int(conversion, draft);
	return ;
}
