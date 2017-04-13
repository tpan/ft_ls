/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 22:37:33 by tpan              #+#    #+#             */
/*   Updated: 2017/04/11 16:16:41 by tpan             ###   ########.fr       */
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

/*
 ** Compare the length of the column and save the largest so the width can be
 ** formatted with printf. Tests S_IFBLK and S_IFCHR (block special and
 ** char special) which indicates that a file is a device. Char devices include
 ** SErial ports, parallel ports and sound cards while block devices include
 ** Hard disks, usb cameras etc.
 */

void		calc_col_width_get_dev_info(t_list *file_list, unsigned int *w)
{
	t_file		*tmp;

	ft_bzero(w, sizeof(int) * 7);
	while (file_list)
	{
		tmp = (t_file *)file_list->content;
		w[0] = MAX(ft_nbrlen(tmp->stats.st_nlink), w[0]);
		if (getpwuid(tmp->stats.st_uid))
			w[1] = MAX(ft_strlen(getpwuid(tmp->stats.st_uid)->pw_name), w[1]);
		else
			w[1] = MAX(ft_strlen(ft_itoa(tmp->stats.st_uid)), w[1]);
		if (getgrgid(tmp->stats.st_gid))
			w[2] = MAX(ft_strlen(getgrgid(tmp->stats.st_gid)->gr_name), w[2]);
		else
			w[2] = MAX(ft_strlen(ft_itoa(tmp->stats.st_gid)), w[2]);
		w[3] = MAX(ft_nbrlen(tmp->stats.st_size), w[3]);
		w[4] = MAX(ft_nbrlen(tmp->stats.st_rdev >> 24), w[4]);
		w[5] = MAX(ft_nbrlen(tmp->stats.st_rdev & 0xFFFFFF), w[5]);
		w[6] = (((tmp->stats.st_mode & S_IFMT) == S_IFBLK) ||
				((tmp->stats.st_mode & S_IFMT) == S_IFCHR) ? 1 : 0);
		file_list = file_list->next;
	}
	w[0]++;
}

/*
** Error messages are thrown if invalid input is given, the functions will
** report an error and exit the program cleanly.
*/

void		unknown_option_error(char c)
{
	ft_putstr_fd("ft_ls: illegal option --", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: ft_ls [-alrRt] [file ...]\n", 2);
	exit(EXIT_FAILURE);
}

void	error_message(char *filename, char *error_msg_prefix, t_bool close)
{
	ft_putstr_fd(filename, 2);
	perror(error_msg_prefix);
	if (close)
		exit(EXIT_FAILURE);
}
