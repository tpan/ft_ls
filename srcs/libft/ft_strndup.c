/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 14:51:12 by tpan              #+#    #+#             */
/*   Updated: 2016/11/11 19:45:11 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char			*str;
	char			*p;
	unsigned long	i;

	i = 0;
	if ((size_t)ft_strlen((char *)s1) < n)
		str = (char *)malloc(sizeof(char) * ft_strlen((char *)s1) + 1);
	else
		str = (char *)malloc(sizeof(char) * (n + 1));
	if (str && n)
	{
		p = str;
		while (*s1 && n > i)
		{
			*p++ = *s1++;
			n--;
		}
		*p = '\0';
		return (str);
	}
	return (NULL);
}
