/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:00:25 by awyart            #+#    #+#             */
/*   Updated: 2017/09/11 19:17:22 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_draw_tree(t_btree *btree, t_flag flag[128])
{
	if (btree)
	{
		ft_draw_tree(root->left, flag);
		ft_printf("size: %s\n", btree->stat->size);
		ft_draw_tree(root->right, flag);
	}
}
