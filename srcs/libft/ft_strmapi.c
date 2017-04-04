/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 20:00:23 by tpan              #+#    #+#             */
/*   Updated: 2016/11/15 14:59:44 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	k;
	char	*string;

	k = 0;
	if (!s || !f)
		return (NULL);
	string = ft_strnew(ft_strlen(s));
	while (string != NULL && s[k] != '\0')
	{
		string[k] = f(k, s[k]);
		k++;
	}
	return (string);
}
