/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:36:37 by awyart            #+#    #+#             */
/*   Updated: 2017/09/16 12:31:01 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void 	ft_insert(t_btree **btree, t_btree *new, char flag[128])
{
	if (flag['t'])
	{
		if (flag['u'])
			btree_insert_u(btree, new, flag);
		else if (flag['U'])
			btree_insert_um(btree, new, flag);	
		else
			btree_insert_d(btree, new, flag);
	}
	else if (flag['S'])
		btree_insert_sm(btree, new, flag);
	else if (flag['f'])
		btree_insert_d(btree, new, flag);
	else
	{
		btree_insert(btree, new, flag);
	}
}
