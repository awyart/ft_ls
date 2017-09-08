/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 11:03:28 by awyart            #+#    #+#             */
/*   Updated: 2017/09/08 16:20:55 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>


typedef struct		s_dir
{
	struct s_file	*equal;
	struct s_file	*child;
	int				filetype;
	/*et tous le rest*/
}					t_dir;

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
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

int			ft_printf(char *format, ...);

#endif