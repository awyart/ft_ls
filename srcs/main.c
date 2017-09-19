/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 11:22:29 by awyart            #+#    #+#             */
/*   Updated: 2017/09/19 15:15:24 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_next(char *init, t_max max, char flag[128], t_btree *btree)
{
	PRINTF("\n%s:\n", init);
	if (flag['l'])
		PRINTF("total %u\n", max.nbblock);
	ft_draw_tree(btree, flag, &max);
	btree_apply_infix(btree, flag);
	ft_free_tree(btree);
}

int			ft_rec_start(char *init, char flag[128])
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
	ft_next(init, max, flag, btree);
	closedir(dir);
	return (0);
}

int			ft_start(char *init, char flag[128])
{
	if (flag['d'] > 0)
		PRINTF("%s\n", init);
	else if (flag['R'] > 0)
		ft_rec_start(init, flag);
	else
		ft_norec_start(init, flag);
	return (0);
}

static void	ft_norm(char *str, char flag[128], int *a, t_btree **btree)
{
	t_btree	*new;
	t_max	max;

	errno = 0;
	if (str[0] == '-' && *a == 0)
		ft_get_option(str, flag);
	else
	{
		*a = 1;
		if (opendir(str) != NULL || errno != ENOTDIR)
		{
			new = btree_create_node(".", str, flag['p']);
			ft_insert(btree, new, flag);
		}
		else
		{
			new = ft_create_spe(str);
			ft_testmax(&max, new);
			ft_draw_tree(new, flag, &max);
			PRINTF("\n");
		}
	}
}

int			main(int ac, char **av)
{
	char	flag[128];
	int		i;
	int		a;
	t_btree	*btree;

	i = -1;
	a = 0;
	btree = NULL;
	while (++i < 128)
		flag[i] = 0;
	i = 1;
	while (i < ac)
	{
		ft_norm(av[i], flag, &a, &btree);
		i++;
	}
	if (a == 0)
		ft_start(".", flag);
	else
	{
		ft_start_tree(btree, flag);
	}
	ft_free_tree(btree);
	return (0);
}
