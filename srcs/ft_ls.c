/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 16:00:15 by tpan              #+#    #+#             */
/*   Updated: 2017/04/09 22:33:40 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_opt		*read_options(int ac, char **argv)
{
	int		i;
	int		j;
	t_opt	*opts;
	opts = ft_memalloc(sizeof(t_opt));
	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (argv[i][0] == '-' && argv[i][j++] != '\0')
		{
			if (!ft_strchr("alrRt", argv[i][j]))
				unknown_option(argv[i][j]);
			opts->a = (argv[i][j] == 'a' ? 1 : opts->a);
			opts->l = (argv[i][j] == 'l' ? 1 : opts->l);
			opts->r = (argv[i][j] == 'r' ? 1 : opts->r);
			opts->up_r = (argv[i][j] == 'R' ? 1 : opts->up_r);
			opts->t = (argv[i][j] == 't' ? 1 : opts->t);
		}
	}
	return (opts);
}

static t_list		*populate_valid_args(int ac, char **argv, int *valid_args)
{
	int			i;
	t_list		*file_list;
	t_file		*tmp;

	i = 0;
	file_list = NULL;
	tmp = (t_file *)ft_memalloc(sizeof(t_file));
	while (++i < ac)
	{
		if (argv[i][0] != '-' && !file_accessible(argv[i]))
		{
			ft_printf("ft_ls: %s: %s", argv[i], strerror(errno));
			(*valid_args)++;
		}
		else if (ft_strchr(&argv[i][0] , '-') == 0 && !ft_strequ(argv[i], 
		"./ft_ls"))
		{
			tmp->name = ft_strdup(argv[i]);
			lstat(tmp->name, &(tmp->stats));
			ft_lst_append(&file_list, ft_lstnew(tmp, sizeof(t_file)));
			(*valid_args)++;
		}
	}
	free(tmp);
	return (file_list);
}

int			main(int argc, char **argv)
{
	t_opt		*opts;
	t_list		*file_list;
	int			list_length;

	opts = read_options(argc, argv);
	file_list = init_list_from_args(argc, argv, opts);
	list_length = ft_lst_len(file_list);
	process_arguements(file_list, opts, list_length);
	ft_lstdel(&file_list, &ft_lst_free);
	free(opts);
	return (0);
}
