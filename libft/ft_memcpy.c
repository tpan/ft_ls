/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:48:20 by tpan              #+#    #+#             */
/*   Updated: 2016/11/06 13:23:32 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long	i;
	char			*d;
	const char		*s;

	i = 0;
	d = dst;
	s = src;
	while (n > 0)
	{
		d[i] = s[i];
		n--;
		i++;
	}
	return (dst);
}
