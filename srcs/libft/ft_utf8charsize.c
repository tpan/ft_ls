/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8charsize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 16:45:52 by tpan              #+#    #+#             */
/*   Updated: 2017/03/20 20:09:47 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the number of bytes needed to represent a UTF-8 character which
** is stored in a wchar_t.
*/

size_t		ft_utf8charsize(wchar_t c)
{
	unsigned int	f;

	f = c;
	if (f <= 0xFF)
		return (1);
	if (f <= 0xFFFF)
		return (2);
	if (f <= 0xFFFFFF)
		return (3);
	if (f <= 0xFFFFFFFF)
		return (4);
	return (0);
}
