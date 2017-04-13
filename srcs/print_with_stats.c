/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_with_stats.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:43:38 by tpan              #+#    #+#             */
/*   Updated: 2017/04/12 22:35:49 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
** Prints file permissions depending on values stored in stats.st_mode.
*/

static void		print_permissions(mode_t mode)
{
	ft_putchar((mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((mode & S_IWUSR) ? 'w' : '-');
	if (mode & S_ISUID)
		ft_putchar((mode & S_IXUSR) ? 's' : 'S');
	else
		ft_putchar((mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((mode & S_IWGRP) ? 'w' : '-');
	if (mode & S_ISGID)
		ft_putchar((mode & S_IXGRP) ? 's' : 'S');
	else
		ft_putchar((mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((mode & S_IROTH) ? 'r' : '-');
	ft_putchar((mode & S_IWOTH) ? 'w' : '-');
	if (mode & S_ISVTX)
		ft_putchar((mode & S_IXUSR) ? 't' : 'T');
	else
		ft_putchar((mode & S_IXOTH) ? 'x' : '-');
}

/*
** Writes the filetype 'd' for directory, 's' for socket etc
*/

static void		print_filetype(mode_t mode)
{
	if ((mode & S_IFMT) == S_IFREG)
		ft_putchar('-');
	else if ((mode & S_IFMT) == S_IFSOCK)
		ft_putchar('s');
	else if ((mode & S_IFMT) == S_IFLNK)
		ft_putchar('l');
	else if ((mode & S_IFMT) == S_IFCHR)
		ft_putchar('c');
	else if ((mode & S_IFMT) == S_IFBLK)
		ft_putchar('b');
	else if ((mode & S_IFMT) == S_IFIFO)
		ft_putchar('f');
	else if ((mode & S_IFMT) == S_IFDIR)
		ft_putchar('d');

}

static void		print_name_or_link(t_file *file, t_file *parent, mode_t mode)
{
	char		link_buf[1024];
	ssize_t		count;
	char		*path;

	if ((mode & S_IFMT) == S_IFLNK)
	{
		ft_bzero(link_buf, sizeof(link_buf));
		if (parent)
			path = ft_strjoin(parent->name, ft_strjoin("/", file->name));
		else
			path = ft_strdup(file->name);
		count = readlink(path, link_buf, sizeof(link_buf));
		if (count < 0)
		{
			free(path);
			perror("readlink");
			exit(EXIT_FAILURE);
		}
		link_buf[count] = '\0';
		ft_printf(" %s -> %s\n", file->name, link_buf);
		free(path);
	}
	else
		ft_printf(" %s\n", file->name);
}

static void		print_time(time_t mod_time)
{
	char	*str;
	char	*start;
	char	*end;
	time_t	ct;

	ct = time(NULL);
	if ((str = ctime(&mod_time)) == NULL)
		return;
	start = str + 4;
	end = str + 10;
	*end = 0;
	ft_putstr(start);
	ft_putchar(' ');
	start = (mod_time > ct || mod_time + SIX_MONTHS < ct) ?
	str + 20 : str + 11;
	end = (mod_time > ct || mod_time + SIX_MONTHS < ct) ?
	str + 24 : (end = str + 16);
	if (mod_time > ct || mod_time + SIX_MONTHS < ct)
		ft_putchar(' ');
	*end = 0;
	ft_putstr(start);
}

/*
** Final formatting and printing.
*/

void			print_with_stats(t_file *file, t_file *parent, unsigned int *i)
{
	print_filetype(file->stats.st_mode);
	ft_printf(" %*d ", i[0], file->stats.st_nlink);
	if (getpwuid(file->stats.st_uid))
		ft_printf(i[6] ? "%-s " : "%*s ", i[1],
			getpwuid(file->stats.st_uid)->pw_name);
	else
		ft_printf(i[6] ? "%-*s " : "%*s ", i[1], ft_itoa(file->stats.st_uid));
	if (getgrgid(file->stats.st_gid))
		ft_printf(i[6] ? "%-*s " : " %*s ", i[2],
			getgrgid(file->stats.st_gid)->gr_name);
	else
		ft_printf(i[6] ? "%-*s " : " %*s ", i[2], ft_itoa(file->stats.st_uid));
	if (i[6])
	{
		if ((file->stats.st_mode & S_IFMT) == S_IFLNK)
			ft_printf("  %*s ", i[4], "");
		else
			ft_printf("  %*d,", i[4], file->stats.st_rdev >> 24);
		ft_printf(" %*d ", i[5], file->stats.st_rdev & 0xFFFFFF);
	}
	else
		ft_printf(" %*lld ", i[3], file->stats.st_size);
	print_time(file->stats.st_mtime);
	print_name_or_link(file, parent, file->stats.st_mode);
}
