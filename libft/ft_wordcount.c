/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 12:21:23 by tpan              #+#    #+#             */
/*   Updated: 2016/11/14 08:18:42 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordcount(char *str, char delimiter)
{
	int i;
	int	flag;
	int	count;

	count = 0;
	flag = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == delimiter)
		{
			count += flag;
			flag = 0;
		}
		else
			flag = 1;
		i++;
	}
	count += flag;
	return (count);
}
