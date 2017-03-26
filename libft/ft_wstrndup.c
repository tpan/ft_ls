/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrndup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 22:07:06 by tpan              #+#    #+#             */
/*   Updated: 2017/03/20 20:11:20 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wstrndup(const wchar_t *s1, size_t n)
{
	wchar_t			*str;
	wchar_t			*p;
	unsigned long	i;

	i = 0;
	if ((size_t)ft_strlen((char *)s1) < n)
		str = (wchar_t *)malloc(sizeof(char) * ft_strlen((char *)s1) + 1);
	else
		str = (wchar_t *)malloc(sizeof(char) * (n + 1));
	if (str && n)
	{
		p = str;
		while (*s1 && n > 1)
		{
			*p++ = *s1++;
			n--;
		}
		*p = '\0';
		return (str);
	}
	return (NULL);
}
