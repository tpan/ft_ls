/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:04:39 by tpan              #+#    #+#             */
/*   Updated: 2016/11/11 11:59:18 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *fresh;

	fresh = malloc(size);
	if (fresh)
	{
		ft_bzero(fresh, size);
		return (fresh);
	}
	else
		return (NULL);
}
