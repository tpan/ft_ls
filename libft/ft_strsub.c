/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 13:33:19 by tpan              #+#    #+#             */
/*   Updated: 2016/11/17 10:36:19 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *fresh;

	if (!s)
		return (NULL);
	if (!(fresh = ft_strnew(len)))
		return (NULL);
	ft_strncpy(fresh, s + start, len);
	return (fresh);
}
