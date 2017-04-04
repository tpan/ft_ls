/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 15:49:05 by tpan              #+#    #+#             */
/*   Updated: 2017/03/12 15:52:58 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wstrdup(wchar_t *str)
{
	wchar_t		*new_str;
	int			i;

	if (!str)
		return (NULL);
	i = 0;
	new_str = (wchar_t *)malloc(sizeof(wchar_t) * ft_wstrlen(str) + 1);
	if (!new_str)
		return (0);
	while (str[i] != '\0')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
