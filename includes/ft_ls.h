/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 19:04:53 by tpan              #+#    #+#             */
/*   Updated: 2017/03/29 12:17:13 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <dirent.h>			opendir(), readdir(), closedir()
** <sys/stat.h>			stat(), lstat()
** <sys/types.h>		dev_t, ino_t (in stat struct)
** <string.h>			strerror()
** <errno.h>			access to errno global variable
** <sys/types.h>		getpwuid()
** <pwd.h>				getpwuid()
** <uuid/uuid.h>		getpwuid(), getgrgid()
** <grp.h>				getgrgid()
*/

#ifndef FT_LS_H
# define FT_LS_H
# define SIX_MONTHS 15552000
# include "libft.h"
# include "ft_printf.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <string.h>
# include <errno.h>
# include <uuid/uuid.h>
# include <grp.h>



#endif
