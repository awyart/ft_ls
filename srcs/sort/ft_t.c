/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 14:44:50 by awyart            #+#    #+#             */
/*   Updated: 2017/09/19 14:06:13 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_tri1(t_btree **root, t_btree *new, char flag[128])
{
	if (flag['r'] == 0)
		btree_insert_t(&((*root)->left), new, flag);
	else
		btree_insert_t(&((*root)->right), new, flag);
}

static void	ft_tri2(t_btree **root, t_btree *new, char flag[128])
{
	if (flag['r'] == 0)
		btree_insert_t(&((*root)->right), new, flag);
	else
		btree_insert_t(&((*root)->left), new, flag);
}

void		btree_insert_t(t_btree **root, t_btree *new, char flag[128])
{
	struct stat info;
	struct stat info2;

	if (!(*root))
		*root = new;
	else
	{
		lstat((*root)->path_name, &info2);
		lstat(new->path_name, &info);
		if (info.st_mtimespec.tv_sec >= info2.st_mtimespec.tv_sec)
		{
			if (info.st_mtimespec.tv_sec == info2.st_mtimespec.tv_sec)
			{
				if (ft_strcmp((*root)->name, new->name) > 0)
					ft_tri1(root, new, flag);
				else
					ft_tri2(root, new, flag);
			}
			else
				ft_tri1(root, new, flag);
		}
		else
			ft_tri2(root, new, flag);
	}
}
