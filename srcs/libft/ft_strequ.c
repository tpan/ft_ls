/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:57:42 by tpan              #+#    #+#             */
/*   Updated: 2016/11/10 16:30:24 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while ((unsigned char)s1[i] == (unsigned char)s2[i])
	{
		if ((unsigned char)s1[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}
