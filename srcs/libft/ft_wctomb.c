/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 15:41:47 by tpan              #+#    #+#             */
/*   Updated: 2017/03/12 15:45:37 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_wctomb(char *s, wchar_t wc)
{
	int		len;
	size_t	i;

	i = 0;
	len = ft_utf8charsize(wc);
	if (len >= 4)
		s[i++] = (0xFF000000 & wc) >> 24;
	if (len >= 3)
		s[i++] = (0xFF0000 & wc) >> 16;
	if (len >= 2)
		s[i++] = (0xFF & wc) >> 8;
	if (len >= 1)
		s[i++] = 0xFF & wc;
	return (len);
}
