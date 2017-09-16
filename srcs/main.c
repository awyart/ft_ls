/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 11:22:29 by awyart            #+#    #+#             */
/*   Updated: 2017/09/16 14:19:15 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void ft_free_tree(t_btree *btree)
{
	if ((btree))
	{
		if ((btree)->left)
			ft_free_tree(((btree)->left));
		if ((btree)->right)	
			ft_free_tree(((btree)->right));
		if (btree->name)
			free(btree->name);
		if (btree->path_name)
			free(btree->path_name);
		free(btree);
	}
}

int		ft_rec_start(char *init, char flag[128])
{
	t_btree *btree = NULL;
	t_btree *new;
	struct dirent *ret;
	DIR *dir;
	t_max max;

	errno = 0;
	dir = opendir(init);
	ft_init_max(&max);
	if (dir == NULL)
	{
		ft_printf("./ft_ls: %s\n\n", strerror(errno));
		return (0);
	}
	while ((ret = readdir(dir)) > 0)
	{
		new = btree_create_node(init, ret->d_name);
		ft_testmax(&max, new);
		ft_insert(&btree, new, flag);
	}
	ft_printf("\n%s:\n", init);
	if (flag['l'])
		ft_printf("total %u\n", max.nbblock);
	ft_draw_tree(btree, flag, &max);
	btree_apply_infix(btree, flag);
	ft_free_tree(btree);
	closedir(dir);
	return (0);
}

int 	ft_norec_start(char *init, char flag[128])
{
	struct dirent *ret;
	t_btree *btree = NULL;
	t_btree *new;
	DIR *dir;
	t_max max;

	errno = 0;
	dir = opendir(init);
	ft_init_max(&max);
	if (dir == NULL)
	{
		ft_printf("./ft_ls: %s\n\n", strerror(errno));
		return (0);
	}
	while ((ret = readdir(dir)) > 0)
	{
		new = btree_create_node(init, ret->d_name);
		ft_testmax(&max, new);
		ft_insert(&btree, new, flag);
	}
	if (flag['l'])
		ft_printf("total %u\n", max.nbblock);
	ft_draw_tree(btree, flag, &max);
	ft_free_tree(btree);
	closedir(dir);
	return (0);
}

int		ft_start(char *init, char flag[128])
{
	if (flag['d'] > 0)
		ft_printf("%s\n", init);
	else if (flag['R'] > 0)
		ft_rec_start(init, flag);
	else
		ft_norec_start(init, flag);
	return (0);
}

static void ft_start_tree(t_btree *btree,char flag[128])
{
	if (btree)
	{
		if (btree->left)
			ft_start_tree(btree->left, flag);
		ft_printf("%s:\n", btree->name);
		ft_start(btree->name, flag);
		if (btree->right)
		{
			ft_printf("\n");
			ft_start_tree(btree->right, flag);
		}
	}
}


int		main(int ac, char **av)
{
	char flag[128];
	int i;
	int a;
	t_btree *btree = NULL;
	t_btree *new;
	t_max max;

	i = -1;
	a = 0;
	errno = 0;
	while (++i < 128)
		flag[i] = 0;
	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-' && a == 0)
			ft_get_option(av[i], flag);
		else
		{
			a = 1;
			if (opendir(av[i]) != NULL || errno != ENOTDIR)
			{
				new = btree_create_node(".", av[i]);
				ft_insert(&btree, new, flag);
			}
			else
			{
				new = ft_create_spe(av[i]);
				ft_testmax(&max, new);
				ft_draw_tree(new, flag, &max);
				ft_printf("\n");
			}	
		}
		i++;
	}
	if (a == 0)
		ft_start(".", flag);
	else
		ft_start_tree(btree, flag);
	ft_free_tree(btree);
	return (0);
}