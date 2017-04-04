/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 12:27:46 by tpan              #+#    #+#             */
/*   Updated: 2016/11/06 13:27:09 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char ch;
	unsigned char *sm;

	ch = ((unsigned char)c);
	sm = ((unsigned char *)s);
	while (n > 0)
	{
		if (*sm == ch)
			return (sm);
		++sm;
		--n;
	}
	return (NULL);
}
