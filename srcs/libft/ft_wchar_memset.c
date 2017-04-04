/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_memset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 15:22:20 by tpan              #+#    #+#             */
/*   Updated: 2017/03/12 15:24:06 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_wchar_memset(void *b, wchar_t c, size_t len)
{
	unsigned int	i;
	wchar_t			*b2;

	b2 = b;
	i = 0;
	while (i < len)
	{
		b2[i] = (wchar_t)c;
		i++;
	}
	return (b);
}
