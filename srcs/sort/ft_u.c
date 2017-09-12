/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 14:39:35 by awyart            #+#    #+#             */
/*   Updated: 2017/09/12 18:18:21 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void btree_insert_u(t_btree **root, char flag[128], char name[256])
{
	t_btree *btree;

	btree = *root;
	if (!(btree))
	{
		btree = btree_create_node(name);
	}
	else if (flag['r'] > 0)
	{
		btree_insert_u(&(btree->left),flag, name);
	}
	else
	{
		btree_insert_u(&(btree->right), flag, name);
	}
}