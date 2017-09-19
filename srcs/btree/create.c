/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:39:45 by awyart            #+#    #+#             */
/*   Updated: 2017/09/19 15:06:34 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_btree	*ft_alloc(char name[1024], char *dir)
{
	t_btree		*btree;

	if (!(btree = malloc(sizeof(t_btree))))
	{
		PRINTF("echec du malloc de l'arbre\n");
		ft_exit();
	}
	if (!(btree->name = (char *)malloc(ft_strlen(name) + 1)))
	{
		PRINTF("echec du malloc de l'arbre: name\n");
		ft_exit();
	}
	if (!(btree->path_name =
		(char *)malloc(ft_strlen(dir) + ft_strlen(name) + 2)))
	{
		PRINTF("echec du malloc du pathname\n");
		ft_exit();
	}
	return (btree);
}

static int		ft_getpath_name(t_btree *btree, char *dir, char name[1024])
{
	int	i;
	int	j;

	i = -1;
	j = 0;
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
	return (i);
}

t_btree			*btree_create_node(char *dir, char name[1024], int a)
{
	t_btree		*btree;
	struct stat	info;
	int			i;

	btree = ft_alloc(name, dir);
	i = ft_getpath_name(btree, dir, name);
	btree->right = NULL;
	btree->left = NULL;
	lstat(btree->path_name, &info);
	btree->filetype = ft_getfiletype(info.st_mode);
	if (a > 0 && btree->filetype == 'd')
	{
		btree->name[i] = '/';
		btree->name[i + 1] = '\0';
	}
	return (btree);
}

static t_btree	*ft_alloc2(char *init)
{
	t_btree		*btree;

	if (!(btree = malloc(sizeof(t_btree))))
	{
		PRINTF("echec du malloc de l'arbre\n");
		ft_exit();
	}
	if (!(btree->name = (char *)malloc(ft_strlen(init) + 1)))
	{
		PRINTF("echec du malloc de l'arbre: name\n");
		ft_exit();
	}
	if (!(btree->path_name = (char *)malloc(ft_strlen(init) + 4)))
	{
		PRINTF("echec du malloc du pathname\n");
		ft_exit();
	}
	return (btree);
}

t_btree			*ft_create_spe(char *init)
{
	t_btree		*btree;
	int			i;
	struct stat	info;

	i = -1;
	btree = ft_alloc2(init);
	btree->path_name[0] = '.';
	btree->path_name[1] = '/';
	while (init[++i] != '\0')
	{
		btree->name[i] = init[i];
		btree->path_name[i + 2] = init[i];
	}
	btree->name[i] = '\0';
	btree->path_name[i + 2] = '\0';
	btree->right = NULL;
	btree->left = NULL;
	lstat(btree->path_name, &info);
	btree->filetype = ft_getfiletype(info.st_mode);
	return (btree);
}
