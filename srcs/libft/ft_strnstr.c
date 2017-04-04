/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:18:35 by tpan              #+#    #+#             */
/*   Updated: 2016/11/17 10:14:43 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int			i;
	int			j;
	int			k;
	char		*s3;

	i = 0;
	if (!*little)
		return ((char *)big);
	s3 = ft_strsub(big, 0, len);
	while (s3[i] != '\0' && len)
	{
		k = i;
		j = 0;
		if (s3[i] == little[j])
			while (s3[k] == little[j])
			{
				j++;
				if (little[j] == '\0')
					return (char *)(&big[i]);
				k++;
				len--;
			}
		i++;
	}
	return (NULL);
}
