/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:00:34 by tpan              #+#    #+#             */
/*   Updated: 2016/11/06 13:22:52 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (s < d && d < s + len)
	{
		d += len;
		s += len;
		while (len > 0)
		{
			*--d = *--s;
			--len;
		}
	}
	else
	{
		while (len > 0)
		{
			*d++ = *s++;
			--len;
		}
	}
	return (dst);
}
