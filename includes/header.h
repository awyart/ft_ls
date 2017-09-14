/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 11:03:28 by awyart            #+#    #+#             */
/*   Updated: 2017/09/14 21:31:59 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <sys/types.h>
#include <uuid/uuid.h>
#include <grp.h>
#include <uuid/uuid.h>
# define OPTIONS "ltrudfRa1TS"
# define _DARWIN_USE_64_BIT_INODE

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	char			*name;
	char 			*path_name;
	char 			filetype;
}					t_btree;

//struct stat
//{ /* when _DARWIN_FEATURE_64_BIT_INODE is defined */
//    dev_t           st_dev;           /* ID of device containing file */
//    mode_t          st_mode;          /* Mode of file (see below) */
//    nlink_t         st_nlink;         /* Number of hard links */
//    ino_t           st_ino;           /* File serial number */
//    uid_t           st_uid;           /* User ID of the file */
//    gid_t           st_gid;           /* Group ID of the file */
//    dev_t           st_rdev;          /* Device ID */
//    struct timespec st_atimespec;     /* time of last access */
//    struct timespec st_mtimespec;     /* time of last data modification */
//    struct timespec st_ctimespec;     /* time of last status change */
//    struct timespec st_birthtimespec; /* time of file creation(birth) */
//    off_t           st_size;          /* file size, in bytes */
//    blkcnt_t        st_blocks;        /* blocks allocated for file */
//    blksize_t       st_blksize;       /* optimal blocksize for I/O */
//    uint32_t        st_flags;         /* user defined flags for file */
//    uint32_t        st_gen;           /* file generation number */
//    int32_t         st_lspare;        /* RESERVED: DO NOT USE! */
//    int64_t         st_qspare[2];     /* RESERVED: DO NOT USE! */
//};

//struct dirent 
//{
//        ino_t      d_fileno;     /* file number of entry */
//        __uint64_t d_seekoff;    /* seek offset (optional, used by servers) */
//        __uint16_t d_reclen;     /* length of this record */
//        __uint16_t d_namlen;     /* length of string in d_name */
//        __uint8_t  d_type;       /* file type, see below */
//        char    d_name[1024];    /* name must be no longer than this */
//};

typedef struct		s_max
{
	unsigned int	mlink;
	unsigned int	muid;
	unsigned int	mgid;
	unsigned int	msize;
	int 			size;
	unsigned int 	nblink;
	char 			uid[32];
	char 			gid[32];
	char 			right[12];
	char 			mdhm[13];
	char 			year[4];
}					t_max;

int					ft_printf(char *format, ...);
void				ft_get_option(char *str, char flag[128]);

t_btree				*btree_create_node(char *dir, char name[1024]);
void				ft_get_content(struct dirent *ret, struct stat stat);
void				ft_draw_tree(t_btree *root, char flag[128], t_max *max);
void				ft_get_option(char *str, char flag[128]);
void				ft_usage(char c);
char				*ft_strchr(char *s, int c);
int					ft_strlen(char *str);
void 				ft_exit(void);
char				*ft_strjoin(char *s1, char *s2);
void				btree_apply_infix(t_btree *root, char flag[128]);
void 				ft_insert(t_btree **btree, t_btree *new, char flag[128]);
void				ft_printfinfo(struct stat *info);
int					ft_strcmp(char *s1, char *s2);
int					ft_rec_start(char *init, char flag[128]);
int					ft_dont_go(t_btree *btree);

void 				btree_insert_d(t_btree **root, t_btree *new, char flag[128]);
void				btree_insert_u(t_btree **root, t_btree *new, char flag[128]);
void				btree_insert(t_btree **root, t_btree *new, char flag[128]);
void				btree_insert_t(t_btree **root, t_btree *new, char flag[128]);
void				btree_insert_um(t_btree **root, t_btree *new, char flag[128]);
void 				btree_insert_f(t_btree **root, t_btree *new, char flag[128]);
void 				btree_insert_sm(t_btree **root, t_btree *new, char flag[128]);
char				*ft_strcpy(char *dst, char *src);	

#endif