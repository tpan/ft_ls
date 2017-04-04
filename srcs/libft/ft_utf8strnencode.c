/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8strnencode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 15:17:25 by tpan              #+#    #+#             */
/*   Updated: 2017/03/20 20:10:53 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Encodes a string of nwchar unicode code points in utf8
*/

t_utf8			*ft_utf8strnencode(const wchar_t *wstr, size_t n)
{
	size_t		i;
	size_t		len;
	wchar_t		c;
	t_utf8		*utf8;

	len = ft_wstrnsize_utf8(wstr, n);
	if (len > 0)
		if ((utf8 = (t_utf8 *)malloc(sizeof(t_utf8) * (len + 1))))
		{
			i = 0;
			while (i < len)
			{
				c = ft_utf8charencode(*wstr);
				i += ft_wctomb(&utf8[i], c);
				wstr++;
			}
			utf8[i] = '\0';
			return (utf8);
		}
	return (NULL);
}
