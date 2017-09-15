/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:00:25 by awyart            #+#    #+#             */
/*   Updated: 2017/09/15 16:38:10 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char ft_getfiletype(mode_t x)
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
		return ('-'); 
	return (0);
}


static void	ft_getright2(mode_t x, char right[12])
{
	right[1] = (x & S_IRUSR ? 'r' : '-');
	right[2] = (x & S_IWUSR ? 'w' : '-');
	if (x & S_ISUID)
		right[3] = (x & S_IXUSR ? 's' : 'S');
	else
		right[3] = (x & S_IXUSR ? 'x' : '-');
	right[4] = (x & S_IRGRP ? 'r' : '-');
	right[5] = (x & S_IWGRP ? 'w' : '-');
	if (x & S_ISGID)
		right[6] = (x & S_IXUSR ? 's' : 'S');
	else
		right[6] = (x & S_IXUSR ? 'x' : '-');
	right[7] = (x & S_IROTH ? 'r' : '-');
	right[8] = (x & S_IWOTH ? 'w' : '-');
	if (x & S_ISVTX)
		right[9] = (x & S_IXUSR ? 't' : 'T');
	else
		right[9] = (x & S_IXUSR ? 'x' : '-');
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

	if (!(gr = getgrgid(info.st_gid)))
		ft_itoa((long long)info.st_gid, max->gid);
	else
		ft_strcpy(max->gid, gr->gr_name);
	if (!(pass = getpwuid(info.st_uid)))
		ft_itoa((long long)info.st_uid, max->uid);
	else
		ft_strcpy(max->uid, pass->pw_name);
	time = ctime(&info.st_atimespec.tv_sec);
	max->nblink = (unsigned int)info.st_nlink;
	max->size = (int)info.st_size;
	max->right[0] = ft_getfiletype(info.st_mode);
	ft_getright2(info.st_mode, max->right);
}

static int ft_draw_l(t_btree *root, char flag[128], t_max *max)
{
	struct stat info;

	if (flag['L'])
	{
		if (stat(root->path_name, &info) == -1)
			return (0);
	}
	else
	{
		if (lstat(root->path_name, &info) == -1)
			return (0);
	}
	ft_getright(info, max);
	ft_gettime(info, max, flag);
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
		ft_printf("%*d %11s %s", max->msize, max->size, max->mdhm, root->name);
		if (max->right[0] == 'l' && !flag['L'])
		{
			readlink(root->path_name, max->link, 64);
			ft_printf(" -> %s\n", max->link);
		}
		else
			ft_printf("\n");
	}
	return (1);
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
