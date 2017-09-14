/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 14:45:07 by awyart            #+#    #+#             */
/*   Updated: 2017/09/14 18:12:58 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void btree_insert_sm(t_btree **root, t_btree *new, char flag[128])
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
		if (info.st_size > info2.st_size)
		{
			btree_insert_sm(&((*root)->left), new, flag);
		}
		else
		{
			btree_insert_sm(&((*root)->right), new, flag);
		}
	}
}