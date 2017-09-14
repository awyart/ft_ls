
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:45:07 by awyart            #+#    #+#             */
/*   Updated: 2017/09/12 18:48:42 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int ft_dont_go(t_btree *btree)
{
	if (btree->filetype == 'd')
		return (0);
	if (ft_strcmp(btree->name, ".") == 0)
		return (0);
	if (ft_strcmp(btree->name, "..") == 0)
		return (0);
	return (1);
}

void	btree_apply_infix(t_btree *root, char flag[128])
{
	if (root)
	{
		if (root->left)
			btree_apply_infix(root->left, flag);
		if (ft_dont_go(root) == 1)
			ft_rec_start(root->path_name, flag);
		if (root->right)
			btree_apply_infix(root->right, flag);
	}
}