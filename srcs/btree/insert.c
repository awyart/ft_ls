/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:45:07 by awyart            #+#    #+#             */
/*   Updated: 2017/09/11 14:42:36 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void btree_insert(t_btree **root, t_stat *stat, int (*cmpf)(void *, void *))
{
	t_btree *btree;

	btree = *root;
	if (!(btree))
	{
		*root = btree_create_node(stat);
	}
	else if ((*cmpf)(item, btree->item) <= 0)
	{
		btree_insert_data(&(btree->left), stat, cmpf);
	}
	else
	{
		btree_insert_data(&(btree->right), stat, cmpf);
	}
}
