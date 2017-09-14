/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 11:22:29 by awyart            #+#    #+#             */
/*   Updated: 2017/09/14 21:26:13 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_rec_start(char *init, char flag[128])
{
	t_btree *btree = NULL;
	t_btree *new;
	struct dirent *ret;
	DIR *dir;
	t_max max;

	dir = opendir(init);
	if (dir == NULL)
		return (0);
	ft_printf("\n%s:\n", init);
	while ((ret = readdir(dir)) > 0)
	{
		new = btree_create_node(init, ret->d_name);
		ft_insert(&btree, new, flag);
	}
	ft_draw_tree(btree, flag, &max);
	btree_apply_infix(btree, flag);
	//free_arbre();
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

	dir = opendir(init);
	if (dir == NULL)
		return (0);
	while ((ret = readdir(dir)) > 0)
	{
		new = btree_create_node(init, ret->d_name);
		ft_insert(&btree, new, flag);
	}
	ft_draw_tree(btree, flag, &max);
	//freearbre();
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
	{
		ft_norec_start(init, flag);
	}
	return (0);
}

int		main(int ac, char **av)
{
	char flag[128];
	int i;
	int a;

	i = -1;
	a = 0;
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
			ft_start(av[i], flag);
		}
		i++;
	}
	if (a == 0)
		ft_start(".", flag);
	return (0);
}