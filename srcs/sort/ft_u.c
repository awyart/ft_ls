/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 14:39:35 by awyart            #+#    #+#             */
/*   Updated: 2017/09/14 17:35:26 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void btree_insert_u(t_btree **root, t_btree *new, char flag[128])
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
		if (info.st_mtimespec.tv_sec <= info2.st_mtimespec.tv_sec)
		{
			btree_insert_u(&((*root)->left), new, flag);
		}
		else
		{
			btree_insert_u(&((*root)->right), new, flag);
		}
	}
}