/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsize_utf8.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 15:58:22 by tpan              #+#    #+#             */
/*   Updated: 2017/03/12 16:01:24 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the number of bytes needed to represent a string of unicode code
** points after it has been encoded to UTF-8.
*/

size_t			ft_wstrsize_utf8(const wchar_t *wstr)
{
	size_t		size;

	if (!wstr)
		return (0);
	size = 0;
	while (*wstr != '\0')
	{
		size += ft_wcharsize_utf8(*wstr);
		wstr++;
	}
	return (size);
}
