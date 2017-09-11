/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 11:22:29 by awyart            #+#    #+#             */
/*   Updated: 2017/09/11 19:16:24 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*int		ft_rec_start(void *ret, DIR *dir)
{
	if ((ret = readdir(dir)))
	{
		creer l'arbre binaire
		afficher l'arbre binaire
		ft_rec_start(ret);
	}
	passer au fichier suivant
	return (0);
}*/

void 	ft_insert(t_stat *statm t_btree *btree, char flag[128])
{
	if (flag['d'])
		btree_insert(btree, stat, flag);
	else if (flag['u'])
		btree_insert(btree, stat, flag);
	else if (flag['U'])
		btree_insert(btree, stat, flag);	
	else if (flag['t'])
		btree_insert(btree, stat, flag);
	else if (flag['S'])
		btree_insert(btree, stat, flag);
	else if (flag['f'])
		btree_insert_d(btree, stat, flag);
}

int		ft_start(char *init, char flag[128])
{
	DIR *dir;
	void *ret;
	t_stat stat;
	t_btree *btree;

	dir = opendir(init);
	if (dir == NULL)
		return (0);
	while (ret = readdir(dir))
	{
		stat = stat(ret);
		ft_insert(&stat, btree, flag);
	}
	ft_draw_tree(btree, flag);
	/*if (flag['R'] == 1)
		ft_rec_start(ret, dir);*/
 	closedir(dir);
	return (0);
}

int		main(int ac, char **av)
{
	char flag[128];
	int i;

	ft_printf("bonjour\n");
	if (ac == 1)
	{
		ft_start(".", flag);
		return (0);
	}
	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-')
			ft_get_option(av[i], flag);
		else if (i == ac - 1)
			ft_start(av[i], flag);
		else
		{
			ft_printf("usage: ./ft_ls [-%s] [file ...]", OPTIONS);
			return (0);
		}
	}
	ft_printf("aurevoir\n");
}