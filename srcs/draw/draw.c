/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:00:25 by awyart            #+#    #+#             */
/*   Updated: 2017/09/12 18:44:32 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_draw_tree(t_btree *btree, char flag[128])
{
	if (btree != NULL)
	{
		ft_draw_tree(btree->left, flag);
		ft_printf("%s\n", btree->name);
		ft_draw_tree(btree->right, flag);
	}
}
