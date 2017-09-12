/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:39:45 by awyart            #+#    #+#             */
/*   Updated: 2017/09/12 18:34:43 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_btree	*btree_create_node(char name[1024])
{
	t_btree		*btree;
	int i;

	i = -1;
	if (!(btree = malloc(sizeof(t_btree *))))
	{
		ft_printf("echec du malloc de l'arbre\n");
		ft_exit();
	}
	while (name[++i] != '\0')
		btree->name[i] = name[i];
	btree->name[i] = '\0';
	btree->right = 0;
	btree->left = 0;
	return (btree);
}
