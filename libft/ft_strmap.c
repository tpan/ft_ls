/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:03:57 by tpan              #+#    #+#             */
/*   Updated: 2016/11/15 14:59:37 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*string;
	size_t	k;

	k = 0;
	if (!s || !f)
		return (NULL);
	string = ft_strnew(ft_strlen(s));
	while (string != NULL && s[k] != '\0')
	{
		string[k] = f(s[k]);
		k++;
	}
	return (string);
}
