/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 14:39:35 by awyart            #+#    #+#             */
/*   Updated: 2017/09/11 14:44:19 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void btree_insert_u(t_btree **root, t_stat *stat)
{
	t_btree *btree;

	btree = *root;
	if (!(btree))
	{
		*root = btree_create_node(stat);
	}
	else if (stat->time < btree->stat->time)
	{
		btree_insert_u(&(btree->left), stat, cmpf);
	}
	else
	{
		btree_insert_u(&(btree->right), stat, cmpf);
	}
}