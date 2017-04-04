/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:26:15 by tpan              #+#    #+#             */
/*   Updated: 2016/11/11 20:13:19 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	char			*d;
	const char		*s;

	i = 0;
	d = dst;
	s = src;
	while (n > 0)
	{
		if (s[i] == c)
		{
			((unsigned char *)d)[i] = s[i];
			return (d + 1 + i);
		}
		((unsigned char *)d)[i] = s[i];
		n--;
		i++;
	}
	return (NULL);
}
