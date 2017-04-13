/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 09:15:40 by tpan              #+#    #+#             */
/*   Updated: 2017/04/12 23:08:06 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
** Prints the total number of blocks used by all files in a given directory
** also prints the block size in kilobits.
*/

static void		print_blocks(t_list *file_list)
{
	blkcnt_t	total;
	int			blksize;

	total = 0;
	if (file_list)
		blksize = ((t_file *)file_list->content)->stats.st_blksize / 1024;
	while (file_list)
	{
		total += ((t_file *)file_list->content)->stats.st_blocks;
		file_list = file_list->next;
	}
	ft_printf("total %zu blocks (%ukb blocksize)\n", total, blksize);
}

/*
** Calls print_blocks to print the total number of blocks used by all files.
** Opens the directory, reads its contents and stores the result and lstat
** values into a list.
*/

static void		print_dir_contents(t_list *parent, t_list *file_list,
															t_opt *opts)
{
	t_list			*entries;
	t_list			*tmp_entries;
	unsigned int	info[7];

	if (!(entries = open_directory(parent, file_list, opts)))
		return ;
	if (opts->l)
		print_blocks(entries);
	lst_sort(entries, (opts->t) ? cmp_lex : cmp_alpha, opts->r);
	tmp_entries = entries;
	calc_col_width_get_dev_info(entries, info);
	while (entries)
	{
		if (opts->l)
			print_with_stats((t_file *)entries->content,
										((t_file *)file_list->content), info);
		else
			ft_printf("%s\n", ((t_file *)entries->content)->name);
		entries = entries->next;
	}
	entries = tmp_entries;
	if (opts->up_r)
		traverse_subdirectories(entries, file_list, opts);
}

void			traverse_subdirectories(t_list *entries, t_list *file_list,
											t_opt *opts)
{
	while (entries)
	{
		if (S_ISDIR(((t_file *)entries->content)->stats.st_mode) &&
				!ft_strequ(((t_file *)entries->content)->name, ".") &&
				!ft_strequ(((t_file *)entries->content)->name, ".."))
			print_dir_contents(file_list, entries, opts);
		entries = entries->next;
	}
	ft_lstdel(&entries, ft_lst_free);
}

static void		process_dir_contents(t_list *file_list, t_opt *opts,
										t_list *prev, int list_len)
{
	if (!ft_strequ(".", ((t_file *)file_list->content)->name))
	{
		if (prev)
			ft_printf("\n");
		if (list_len > 1)
			ft_printf("%s:\n", ((t_file *)file_list->content)->name);
	}
	print_dir_contents(NULL, file_list, opts);
}

void			process_arguments(t_list *file_list, t_opt *opts, int list_len)
{
	t_list			*prev;
	unsigned int	info[7];

	prev = NULL;
	calc_col_width_get_dev_info(file_list, info);
	while (file_list)
	{
		if (S_ISDIR(((t_file *)file_list->content)->stats.st_mode))
			process_dir_contents(file_list, opts, prev, list_len);
		else
		{
			if (opts->l)
				print_with_stats((t_file *)file_list->content, NULL, info);
			else
				ft_printf("%s\n", ((t_file *)file_list->content)->name);
		}
		prev = file_list;
		file_list = file_list->next;
	}
}
