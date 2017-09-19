/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 14:27:28 by awyart            #+#    #+#             */
/*   Updated: 2017/09/19 15:07:11 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_dont_go(t_btree *btree, char flag[128])
{
	if (ft_strcmp(btree->name, ".") == 0)
		return (0);
	if (ft_strcmp(btree->name, "..") == 0)
		return (0);
	if (flag['a'] == 0 && btree->name[0] == '.')
		return (0);
	return (1);
}

void	btree_apply_infix(t_btree *root, char flag[128])
{
	if (root)
	{
		if (root->left)
			btree_apply_infix(root->left, flag);
		if (ft_dont_go(root, flag) == 1 && root->filetype == 'd')
			ft_rec_start(root->path_name, flag);
		if (root->right)
			btree_apply_infix(root->right, flag);
	}
}

void	ft_free_tree(t_btree *btree)
{
	if ((btree))
	{
		if ((btree)->left)
			ft_free_tree(((btree)->left));
		if ((btree)->right)
			ft_free_tree(((btree)->right));
		if (btree->name)
			free(btree->name);
		if (btree->path_name)
			free(btree->path_name);
		free(btree);
	}
}

void	ft_start_tree(t_btree *btree, char flag[128])
{
	if (btree)
	{
		if (btree->left)
			ft_start_tree(btree->left, flag);
		if (btree->filetype != 'd')
			PRINTF("%s:\n", btree->name);
		ft_start(btree->name, flag);
		if (btree->right)
			ft_start_tree(btree->right, flag);
	}
}
