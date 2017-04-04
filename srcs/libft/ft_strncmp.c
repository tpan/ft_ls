/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 21:30:35 by tpan              #+#    #+#             */
/*   Updated: 2016/11/14 16:24:30 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
		{
			return (*(unsigned char *)s1 - (*(unsigned char *)s2));
		}
		else if (*s1 == '\0')
			return (0);
		++s1;
		++s2;
		n--;
	}
	return (0);
}
