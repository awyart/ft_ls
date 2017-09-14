/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:00:25 by awyart            #+#    #+#             */
/*   Updated: 2017/09/14 21:38:57 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char ft_getfiletype(mode_t x)
{
	if (x & S_IFIFO)
		return ('p'); 
	if (x & S_IFCHR)
		return ('c'); 
	if (x & S_IFDIR)
		return ('d'); 
	if (x & S_IFBLK)
		return ('b'); 
	if (x & S_IFREG)
		return ('-'); 
	if (x & S_IFLNK)
		return ('l'); 
	if (x & S_IFSOCK)
		return ('s');
	return (0);
}


static void 	ft_getright2(mode_t x, char right[12])
{
	right[1] = (x & S_IRUSR ? 'r' : '-');
	right[2] = (x & S_IWUSR ? 'w' : '-');
	right[3] = (x & S_IXUSR ? 'x' : '-');
	right[4] = (x & S_IRGRP ? 'r' : '-');
	right[5] = (x & S_IWGRP ? 'w' : '-');
	right[6] = (x & S_IXGRP ? 'x' : '-');
	right[7] = (x & S_IROTH ? 'r' : '-');
	right[8] = (x & S_IWOTH ? 'w' : '-');
	right[9] = (x & S_IXOTH ? 'x' : '-');
	right[10] = ' ';
	right[11] = '\0';
}

static void ft_gettime(struct stat info, t_max *max, char flag[128])
{
	char *time;
	int i;

	if (flag['u'])
		time = ctime(&info.st_atimespec.tv_sec);
	else if (flag['U'])
		time = ctime(&info.st_birthtimespec.tv_sec);
	else
		time = ctime(&info.st_mtimespec.tv_sec);
	i = 0;
	while (i < 12)
	{
		max->mdhm[i] = time[i + 4];
		i++;
	}
	max->mdhm[12] = '\0';
	max->year[0] = time[22];
	max->year[1] = time[23];
	max->year[2] = time[24];
	max->year[3] = time[25];
}

static void 	ft_getright(struct stat info, t_max *max)
{
	struct passwd *pass;
	char *time;
	struct group *gr;

	gr = getgrgid(info.st_gid);
	pass = getpwuid(info.st_uid);
	time = ctime(&info.st_atimespec.tv_sec);
	ft_strcpy(max->uid, pass->pw_name);
	ft_strcpy(max->gid, gr->gr_name);
	max->nblink = (unsigned int)info.st_nlink;
	max->size = (int)info.st_size;
	max->right[0] = ft_getfiletype(info.st_mode);
	ft_getright2(info.st_mode, max->right);
}

static void ft_draw_l(t_btree *root, char flag[128], t_max *max)
{
	struct stat info;

	stat(root->path_name, &info);
	ft_getright(info, max);
	ft_gettime(info, max, flag);
	max->mlink = 2;
	max->muid = 6;
	max->mgid = 10;
	max->msize = 5;
	if (max->right[0] == 'c' || max->right[0] == 'b')
	{
		ft_printf("%-11s %*u ",max->right, max->mlink, max->nblink);
		ft_printf("%*s  %*s ", max->muid, max->uid, max->mgid, max->gid);
		ft_printf("%3d, ",major(info.st_rdev));
		ft_printf("%*d %11s %s\n", max->msize, minor(info.st_rdev), max->mdhm, root->name);
	}
	else
	{
		ft_printf("%-11s %*u ",max->right, max->mlink, max->nblink);
		ft_printf("%*s  %*s  ", max->muid, max->uid, max->mgid, max->gid);
		ft_printf("%*d %11s %s\n", max->msize, max->size, max->mdhm, root->name);
	}
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
				ft_printf("%s\n", (root)->name);
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
