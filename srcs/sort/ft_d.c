/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 14:35:27 by awyart            #+#    #+#             */
/*   Updated: 2017/09/11 14:43:56 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void btree_insert_d(btree, stat, flag)
{
	t_btree *btree;

	btree = *root;
	if (!(btree))
	{
		*root = btree_create_node(stat);
	}
	else if (flag['r'] == 1)
	{
		btree_insert_d(&(btree->left), stat, cmpf);
	}
	else
	{
		btree_insert_d(&(btree->right), stat, cmpf);
	}
}
