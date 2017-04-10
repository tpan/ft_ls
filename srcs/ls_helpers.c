/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 22:37:33 by tpan              #+#    #+#             */
/*   Updated: 2017/04/09 22:56:16 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/* Returns (1) if lstat finds a valid and accesible file. Else it will print an**error message and return (0).
*/

t_bool		file_accessible(char *filename)
{
	struct stat		stbuf;

	if (lstat(filename, &stbuf) == 0)
		return (1);
	else
	{
		ft_printf("ft_ls: %s: %s", filename, strerror(errno));
		return (0);
	}
}


