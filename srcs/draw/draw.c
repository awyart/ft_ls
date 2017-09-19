/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:00:25 by awyart            #+#    #+#             */
/*   Updated: 2017/09/19 15:07:45 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
	right[10] = '\0';
}

static void	ft_gettime(struct stat info, t_max *max, char flag[128])
{
	char	*time;
	int		i;

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

static void	ft_getright(struct stat info, t_max *max)
{
	struct passwd	*pass;
	char			*time;
	struct group	*gr;

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

static void	ft_print_dirli(t_max *max, t_btree *root,
					char flag[128], struct stat info)
{
	PRINTF("%-10s  %*u ", max->right, max->mlink, max->nblink);
	PRINTF("%-*s  %-*s  ", max->muid, max->uid, max->mgid, max->gid);
	PRINTF("%3d,", major(info.st_rdev));
	PRINTF("%*d %11s ", max->msize, minor(info.st_rdev), max->mdhm);
	if (flag['G'])
	{
		ft_printcolor(max);
		PRINTF("%s\033[00m\n", root->name);
	}
	else
		PRINTF("%s\n", root->name);
}

int			ft_draw_l(t_btree *root, char flag[128], t_max *max)
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
		ft_print_dirli(max, root, flag, info);
	else
		ft_print_oth(max, root, flag);
	return (1);
}
