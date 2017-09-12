/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 11:22:29 by awyart            #+#    #+#             */
/*   Updated: 2017/09/12 18:35:04 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*int		ft_rec_start(char *init, char flag[128])
{
	t_btree *btree;
	struct dirent *ret;
	struct stat info;
	DIR *dir;

	dir = opendir(init);
	if (dir == NULL)
		return (0);
	while ((ret = readdir(dir)) > 0)
	{
		stat(ret->d_name, &info);
		if (!(btree))
			btree = btree_create_node(ret->d_name);
		else
			ft_insert(btree, flag, ret->d_name);
	}
	ft_draw_tree(btree, flag);
	btree_apply_infix(btree, flag,  &ft_rec_start);
	//free_arbre();
	return (0);
}*/


void ft_draw_btree(t_btree *btree)
{
	ft_printf("%s\n", btree->name);
	//ft_printf("\tdev   [%d]\n", btree->info->st_mode);
	//ft_printf("\tmode  [%d]\n", btree->info->st_nlink);
	//ft_printf("\tnlink [%d]\n", btree->info->st_ino);
	//ft_printf("\tino   [%d]\n", btree->info->st_uid);
	//ft_printf("\tuid   [%d]\n", btree->info->st_gid);
	//ft_printf("\tgid   [%d]\n", btree->info->st_rdev);
	//ft_printf("\tatime [%d]\n", btree->info->st_atimespec);
	//ft_printf("\tmtime [%d]\n", btree->info->st_mtimespec);
	//ft_printf("\tctime [%d]\n", btree->info->st_ctimespec);
	//ft_printf("\tbtime [%d]\n", btree->info->st_birthtimespec);
	//ft_printf("\tsize [%d]\n", btree->info->st_size);
	//ft_printf("\tblock [%d]\n", btree->info->st_blocks);
	//ft_printf("\tblksize [%d]\n", btree->info->st_blksize);
	//ft_printf("\tflags [%d]\n", btree->info->st_flags);
	//ft_printf("\tgen [%d]\n", btree->info->st_gen);
	//ft_printf("\n");
}

void ft_printfinfo(struct stat *info)
{
	ft_printf("\tdev   [%d]\n", info->st_mode);
	ft_printf("\tmode  [%d]\n", info->st_nlink);
	ft_printf("\tnlink [%d]\n", info->st_ino);
	ft_printf("\tino   [%d]\n", info->st_uid);
	ft_printf("\tuid   [%d]\n", info->st_gid);
	ft_printf("\tgid   [%d]\n", info->st_rdev);
	ft_printf("\tatime [%d]\n", info->st_atimespec);
	ft_printf("\tmtime [%d]\n", info->st_mtimespec);
	ft_printf("\tctime [%d]\n", info->st_ctimespec);
	ft_printf("\tbtime [%d]\n", info->st_birthtimespec);
	ft_printf("\tsize [%d]\n", info->st_size);
	ft_printf("\tblock [%d]\n", info->st_blocks);
	ft_printf("\tblksize [%d]\n", info->st_blksize);
	ft_printf("\tflags [%d]\n", info->st_flags);
	ft_printf("\tgen [%d]\n", info->st_gen);
	ft_printf("\n");

}

int		ft_start(char *init, char flag[128])
{
	DIR *dir;
	struct dirent *ret;
	t_btree *btree;

	dir = opendir(init);
	if (dir == NULL)
		return (0);
	if (flag['R'] == 0)
	{
		while ((ret = readdir(dir)) > 0)
		{
			if (!(btree))
			{
				btree = btree_create_node(ret->d_name);
			}
			else
			{
				ft_insert(btree, flag, ret->d_name);
			}
		}
		ft_draw_tree(btree, flag);
		//freearbre();
	}
	/*else
	{
		ft_printf("GO RECURSIVE\n");
		ft_rec_start(init, flag);
	}*/
 	closedir(dir);
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