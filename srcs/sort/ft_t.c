/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 14:44:50 by awyart            #+#    #+#             */
/*   Updated: 2017/09/15 13:34:58 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void btree_insert_t(t_btree **root, t_btree *new, char flag[128])
{
	struct stat info;
	struct stat info2;

	if (!(*root))
	{
		*root = new;
	}
	else
	{
		lstat((*root)->path_name, &info2);
		lstat(new->path_name, &info);
		if (info.st_atimespec.tv_sec < info2.st_atimespec.tv_sec)
		{
			btree_insert_t(&((*root)->left), new, flag);
		}
		else
		{
			btree_insert_t(&((*root)->right), new, flag);
		}
	}
}
