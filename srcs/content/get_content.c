/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:36:37 by awyart            #+#    #+#             */
/*   Updated: 2017/09/15 14:20:04 by awyart           ###   ########.fr       */
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
		btree_insert_sm(btree, new, flag); // attention aux liens
	else if (flag['f'])
		btree_insert_d(btree, new, flag);
	else
	{
		btree_insert(btree, new, flag);
	}
}

void ft_printfinfo(struct stat *info)
{
	ft_printf("\tdev   [%d]\n", info->st_mode);
	ft_printf("\tmode  [%d]\n", info->st_nlink);
	ft_printf("\tnlink [%d]\n", info->st_ino);
	ft_printf("\tino   [%d]\n", info->st_uid);
	ft_printf("\tuid   [%d]\n", info->st_gid);
	ft_printf("\tgid   [%d]\n", info->st_rdev);
	ft_printf("\tatime [%d]\n", info->st_atimespec);
	ft_printf("\tmtime [%d]\n", info->st_mtimespec);
	ft_printf("\tctime [%d]\n", info->st_ctimespec);
	ft_printf("\tbtime [%d]\n", info->st_birthtimespec);
	ft_printf("\tsize [%d]\n", info->st_size);
	ft_printf("\tblock [%d]\n", info->st_blocks);
	ft_printf("\tblksize [%d]\n", info->st_blksize);
	ft_printf("\tflags [%d]\n", info->st_flags);
	ft_printf("\tgen [%d]\n", info->st_gen);
	ft_printf("\n");

}