/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 11:43:03 by awyart            #+#    #+#             */
/*   Updated: 2017/09/16 14:11:27 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static unsigned int ft_size(unsigned int a)
{
	int i;

	i = 0;
	while ((a /= 10) != 0)
		i++;
	return (i + 1);

}

void				ft_init_max(t_max *max)
{
	int i;

	i = -1;
	max->mlink = 0;
	max->muid = 0;
	max->mgid = 0;
	max->msize = 0;
	max->nbblock = 0;
	while (++i < 1024)
		max->uid[i] = '\0';
	i = -1;
	while (++i < 1024)
		max->gid[i] = '\0';
	i = -1;
	while (++i < 12)
		max->right[i] = '\0';
	i = -1;
	while (++i < 13)
		max->mdhm[i] = '\0';
	i = -1;
	while (++i < 4)
		max->year[i] = '\0';
	i = -1;
	while (++i < 1024)
		max->link[i] = '\0';
}


void				ft_testmax(t_max *max,t_btree *new)
{
	struct stat		info;
	unsigned int	sizename;
	unsigned int	sizegroup;
	struct passwd 	*pass;
	struct group 	*gr;

	sizename = 0;
	sizegroup = 0;
	lstat(new->path_name, &info);
	max->nbblock += (unsigned int)info.st_blocks;
	if ((pass = getpwuid(info.st_uid)))
		sizename = ft_strlen(pass->pw_name);
	if ((gr = getgrgid(info.st_gid)))
		sizegroup = ft_strlen(gr->gr_name);
	if (ft_size((unsigned int)info.st_size) > max->msize)
		max->msize = ft_size((unsigned int)(info.st_size));
	if (sizename > max->muid)
		max->muid = sizename;
	if (sizegroup > max->mgid)
		max->mgid = sizegroup;
	if (ft_size((unsigned int)info.st_nlink) > max->mlink)
		max->mlink = ft_size((unsigned int)info.st_nlink);
}