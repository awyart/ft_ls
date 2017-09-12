/* ************************************************************************** */
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

void	btree_apply_infix(t_btree *root, char flag[128], int (*applyf)(char *init, char flag[128]))
{
	if (!(root))
	{
		btree_apply_infix(root->left, flag, (*applyf));
		(*applyf)(root->name, flag);
		ft_printf("ssss%s\n", root->name);
		btree_apply_infix(root->right, flag, (*applyf));
	}
}