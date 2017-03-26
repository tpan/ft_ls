/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:51:12 by tpan              #+#    #+#             */
/*   Updated: 2016/11/03 16:29:11 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *su1;
	const unsigned char *su2;

	su1 = s1;
	su2 = s2;
	while (n > 0)
	{
		if (*su1 != *su2)
			return (*su1 - *su2);
		su1++;
		su2++;
		n--;
	}
	return (0);
}
