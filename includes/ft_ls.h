/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 19:04:53 by tpan              #+#    #+#             */
/*   Updated: 2017/04/12 23:06:45 by tpan             ###   ########.fr       */
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

typedef struct		s_opt
{
	unsigned int	l : 1;
	unsigned int	up_r : 1;
	unsigned int	a : 1;
	unsigned int	r : 1;
	unsigned int	t : 1;
}					t_opt;

typedef struct		s_file
{
	char			*name;
	struct stat		stats;
}					t_file;

t_bool				file_accessible(char *filename);
void				unknown_option(char c);
void				error_message(char *name, char *error_message_prefix,
					t_bool close);
void				process_arguments(t_list *file_list, t_opt *opts,
					int list_len);
void				calc_col_width_get_dev_info(t_list *file_list,
					unsigned int *width);
void				traverse_subdirectories(t_list *entries, t_list *file_list,
					t_opt *opts);
void				lst_sort(t_list *start, int (*f)(t_file *, t_file *, int),
					int reverse_cmp);
int					cmp_lex(t_file *p1, t_file *p2, int reverse_cmp);
int					cmp_alpha(t_file *p1, t_file *p2, int reverse_cmp);
t_list				*open_directory(t_list *parent, t_list *file_list,
					t_opt *opts);
void				print_with_stats(t_file *file, t_file *parent,
					unsigned int *info);

#endif
