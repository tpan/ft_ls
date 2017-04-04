/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnsize_utf8.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 15:54:11 by tpan              #+#    #+#             */
/*   Updated: 2017/03/20 20:01:24 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the number of bytes needed to represent a string of up to 'n' unicode
** code points after it has been encoded to UTF-8.
*/

size_t			ft_wstrnsize_utf8(const wchar_t *wstr, size_t n)
{
	size_t		size;
	size_t		i;

	if (!wstr)
		return (0);
	i = 0;
	size = 0;
	while (wstr[i] != '\0' && i < n)
		size += ft_wcharsize_utf8(wstr[i++]);
	return (size);
}
