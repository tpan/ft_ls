/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 08:15:02 by tpan              #+#    #+#             */
/*   Updated: 2016/12/14 08:21:46 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**Takes a pointer and size, re-memory allocates to accommadate a larger buff
*/
#include <stdlib.h>

char	*ft_realloc(char *ptr, size_t size)
{
	char	*temp;
	int		i;

	temp = ptr;
	ptr = malloc(size);
	i = 0;
	while (temp[i])
	{
		ptr[i] = temp[i];
		i++;
	}
	free(temp);
	return (ptr);
}
