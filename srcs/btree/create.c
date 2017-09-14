/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:39:45 by awyart            #+#    #+#             */
/*   Updated: 2017/09/14 16:14:18 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_btree	*btree_create_node(char *dir, char name[1024])
{
	t_btree		*btree;
	int i;
	int j;

	i = -1;
	j = 0;
	if (!(btree = malloc(sizeof(t_btree))))
	{
		ft_printf("echec du malloc de l'arbre\n");
		ft_exit();
	}
	if (!(btree->name = (char *)malloc(ft_strlen(name) + 1)))
	{
		ft_printf("echec du malloc de l'arbre: name\n");
		ft_exit();
	}
	if (!(btree->path_name = (char *)malloc(ft_strlen(dir) + ft_strlen(name) + 2)))
	{
		ft_printf("echec du malloc du pathname\n");
		ft_exit();
	}
	while (dir[j] != '\0')
	{
		btree->path_name[j] = dir[j];
		j++;
	}
	btree->path_name[j] = '/';
	j++;
	while (name[++i] != '\0')
	{
		btree->name[i] = name[i];
		btree->path_name[j] = name[i];
		j++;
	}
	btree->name[i] = '\0';
	btree->path_name[j] = '\0';
	btree->right = NULL;
	btree->left = NULL;
	return (btree);
}
