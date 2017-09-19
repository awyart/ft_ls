/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 12:01:23 by awyart            #+#    #+#             */
/*   Updated: 2017/09/19 15:09:00 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	ft_getfiletype(mode_t x)
{
	if (S_ISLNK(x))
		return ('l');
	if (S_ISREG(x))
		return ('-');
	if (S_ISDIR(x))
		return ('d');
	if (S_ISCHR(x))
		return ('c');
	if (S_ISBLK(x))
		return ('b');
	if (S_ISFIFO(x))
		return ('p');
	if (S_ISSOCK(x))
		return ('s');
	return (0);
}

void	ft_printcolor(t_max *max)
{
	if (max->right[0] == 'c')
		PRINTF("\033[34;43m");
	else if (max->right[0] == 'b')
		PRINTF("\033[32;47m");
	else if (max->right[0] == 'd')
		PRINTF("\033[33m");
	else if (max->right[0] == 'l')
		PRINTF("\033[34m");
	else if (max->right[0] == 'p')
		PRINTF("\033[35m");
	else
		PRINTF("\033[36m");
}

void	ft_print_oth(t_max *max, t_btree *root, char flag[128])
{
	int i;

	i = -1;
	PRINTF("%-10s  %*u ", max->right, max->mlink, max->nblink);
	PRINTF("%-*s  %-*s  ", max->muid, max->uid, max->mgid, max->gid);
	PRINTF("%*d %11s ", max->msize, max->size, max->mdhm);
	if (flag['G'])
	{
		ft_printcolor(max);
		PRINTF("%s\033[00m", root->name);
	}
	else
		PRINTF("%s", root->name);
	if (max->right[0] == 'l' && !flag['L'])
	{
		readlink(root->path_name, max->link, 64);
		PRINTF(" -> %s\n", max->link);
		while (++i < 1024)
			max->link[i] = '\0';
	}
	else
		PRINTF("\n");
}

void	ft_draw_tree(t_btree *root, char flag[128], t_max *max)
{
	if ((root))
	{
		if ((root)->left)
			ft_draw_tree(((root)->left), flag, max);
		if (flag['l'] == 0)
		{
			if (!(flag['a'] == 0 && root->name[0] == '.'))
				PRINTF("%s\n", (root)->name);
		}
		else
		{
			if (!(flag['a'] == 0 && root->name[0] == '.'))
				ft_draw_l(root, flag, max);
		}
		if ((root)->right)
			ft_draw_tree(((root)->right), flag, max);
	}
}
