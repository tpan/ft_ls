/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 21:21:17 by tpan              #+#    #+#             */
/*   Updated: 2016/11/11 19:45:37 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int			i;
	int			j;
	int			k;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (big[i] != '\0')
	{
		j = 0;
		if (big[i] == little[j])
		{
			k = i;
			while (big[k] == little[j])
			{
				j++;
				if (little[j] == '\0')
					return (char *)(&big[i]);
				k++;
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
