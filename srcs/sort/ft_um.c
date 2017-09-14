/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_um.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 14:44:37 by awyart            #+#    #+#             */
/*   Updated: 2017/09/14 18:11:59 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

void btree_insert_um(t_btree **root, t_btree *new, char flag[128])
{
	struct stat info;
	struct stat info2;

	if (!(*root))
	{
		*root = new;
	}
	else
	{
		stat((*root)->path_name, &info2);
		stat(new->path_name, &info);
		if (info.st_birthtimespec.tv_sec <= info2.st_birthtimespec.tv_sec)
		{
			btree_insert_um(&((*root)->left), new, flag);
		}
		else
		{
			btree_insert_um(&((*root)->right), new, flag);
		}
	}
}