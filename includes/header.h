/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 11:03:28 by awyart            #+#    #+#             */
/*   Updated: 2017/09/11 19:16:36 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
# define OPTIONS "ltrRa1TS"


typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	struct s_stat	*info;
}					t_btree;

typedef struct 		s_stat
{
	dev_t			st_dev;     /* ID of device containing file */
	ino_t			st_ino;     /* inode number */
	mode_t			st_mode;    /* protection */
	nlink_t			st_nlink;   /* number of hard links */
	uid_t			st_uid;     /* user ID of owner */
	gid_t			st_gid;     /* group ID of owner */
	dev_t			st_rdev;    /* device ID (if special file) */
	off_t			st_size;    /* total size, in bytes */
	blksize_t		st_blksize; /* blocksize for file system I/O */
	blkcnt_t		st_blocks;  /* number of 512B blocks allocated */
	time_t			st_atime;   /* time of last access */
	time_t			st_mtime;   /* time of last modification */
	time_t			st_ctime;   /* time of last status change */
};

int					ft_printf(char *format, ...);
void				ft_get_option(char *str, char flag[128]);

void				btree_insert(t_btree **root, t_stat *stat);
t_btree				*btree_create_node(t_stat *stat);

#endif