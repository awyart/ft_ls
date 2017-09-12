/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 14:35:27 by awyart            #+#    #+#             */
/*   Updated: 2017/09/12 18:59:56 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void btree_insert_d(t_btree **root, char flag[128], char name[1024])
{
	t_btree *btree;
	//struct stat info;
	//struct stat info2;

	btree = *root;
	/*if (btree)
	{
		stat(btree->name, &info2);
		stat(name, &info);
	}*/
	//ft_printfinfo(&info2);
	//ft_draw_btree(btree);
	//if (btree)
	//	ft_printf("%s <><>%s\n", name, btree->name);
	if (!(btree))
	{
		btree = btree_create_node(name);
		printf("%s\n", btree->name);
	}
	else if (ft_strcmp(name, btree->name) < 0)
	{
		//ft_printf("okokok\n");
		btree_insert_d(&(btree->left), flag, name);
	}
	else
	{
		btree_insert_d(&(btree->right), flag, name);
	}
}
