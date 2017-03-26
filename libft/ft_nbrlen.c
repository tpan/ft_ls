/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 13:53:39 by tpan              #+#    #+#             */
/*   Updated: 2017/03/20 20:06:54 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the amount of digits in a number. Useful for preparing an array of
** of chars to hold a number.
*/

size_t		ft_nbrlen(int nbr)
{
	size_t		len;

	if (nbr == 0)
		return (0);
	len = 1;
	while (nbr /= 10)
		len++;
	return (len);
}
