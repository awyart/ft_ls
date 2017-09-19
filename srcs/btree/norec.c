/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norec.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 12:31:48 by awyart            #+#    #+#             */
/*   Updated: 2017/09/19 15:06:58 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_next(t_max max, t_btree *btree, char flag[128])
{
	if (flag['l'])
		PRINTF("total %u\n", max.nbblock);
	ft_draw_tree(btree, flag, &max);
	ft_free_tree(btree);
}

int			ft_norec_start(char *init, char flag[128])
{
	t_btree			*btree;
	t_btree			*new;
	struct dirent	*ret;
	DIR				*dir;
	t_max			max;

	errno = 0;
	btree = NULL;
	dir = opendir(init);
	ft_init_max(&max);
	if (dir == NULL)
	{
		PRINTF("./ft_ls: %s: %s\n", init, strerror(errno));
		return (0);
	}
	while ((ret = readdir(dir)) > 0)
	{
		new = btree_create_node(init, ret->d_name, flag['p']);
		ft_testmax(&max, new);
		ft_insert(&btree, new, flag);
	}
	ft_next(max, btree, flag);
	closedir(dir);
	return (0);
}
