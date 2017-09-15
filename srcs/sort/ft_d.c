/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 14:35:27 by awyart            #+#    #+#             */
/*   Updated: 2017/09/15 16:02:10 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void btree_insert(t_btree **root, t_btree *new, char flag[128])
{
	if (!(*root))
	{
		*root = new;
	}
	else
	{
		if (ft_strcmp((*root)->name, new->name) > 0)
		{
			btree_insert(&((*root)->left), new, flag);
		}
		else
		{
			btree_insert(&((*root)->right), new, flag);
		}
	}
}

void btree_insert_d(t_btree **root, t_btree *new, char flag[128])
{
	if (!(*root))
	{
		*root = new;
	}
	else if (0)
	{
		btree_insert_d(&((*root)->left), new, flag);
	}
	else
	{
		btree_insert_d(&((*root)->right), new, flag);
	}
}
