/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:39:45 by awyart            #+#    #+#             */
/*   Updated: 2017/09/11 13:48:56 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_btree	*btree_create_node(t_stat *stat)
{
	t_btree		*btree;

	if (!(btree = malloc(sizeof(*btree))))
	{
		ft_printf("echec du malloc de l'arbre\n");
		exit(0);
	}
	if (!(btree->info = malloc(sizeof(t_stat *)))
	{
		ft_printf("echec du malloc du premier noeud de l'arbre\n");
		exit(0);
	}
	btree->info = stat;
	btree->right = 0;
	btree->left = 0;
	return (btree);
}
