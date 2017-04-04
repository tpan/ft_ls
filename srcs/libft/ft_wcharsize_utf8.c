/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharsize_utf8.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 15:25:51 by tpan              #+#    #+#             */
/*   Updated: 2017/03/20 20:09:23 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the number of bytes that will be needed to represent a unicode
** code point in UTF-8 format.
*/

size_t		ft_wcharsize_utf8(wchar_t c)
{
	size_t bits;

	bits = ft_wcharbits(c);
	if (bits <= 7)
		return (1);
	if (bits <= 11)
		return (2);
	if (bits <= 16)
		return (3);
	if (bits <= 21)
		return (4);
	else
		return (0);
}
