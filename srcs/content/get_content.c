/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:36:37 by awyart            #+#    #+#             */
/*   Updated: 2017/09/12 18:57:42 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void 	ft_insert(t_btree *btree, char flag[128], char name[1024])
{
	if (flag['d'])
		btree_insert_d(&(btree), flag, name);
	else if (flag['u'])
		btree_insert_d(&(btree), flag, name);
	else if (flag['U'])
		btree_insert_d(&(btree), flag, name);	
	else if (flag['t'])
		btree_insert_d(&(btree), flag, name);
	else if (flag['S'])
		btree_insert_d(&(btree), flag, name);
	else if (flag['f'])
		btree_insert_d(&(btree), flag, name);
	else
		btree_insert_d(&(btree), flag, name);
}
