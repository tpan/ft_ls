/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharbits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 15:24:15 by tpan              #+#    #+#             */
/*   Updated: 2017/03/20 20:00:58 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Count number of bits needed to represent a unicode code point.
*/

size_t		ft_wcharbits(wchar_t c)
{
	size_t		i;

	i = 0;
	while (c > 0)
	{
		c = c >> 1;
		i++;
	}
	return (i);
}
