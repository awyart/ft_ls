/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 11:03:28 by awyart            #+#    #+#             */
/*   Updated: 2017/09/16 14:23:22 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <dirent.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <time.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <pwd.h>
# include <sys/types.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <errno.h>
# define OPTIONS "GlLtruUdfRa1TS"
# define _DARWIN_USE_64_BIT_INODE

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	char			*name;
	char			*path_name;
	char			filetype;
}					t_btree;

typedef struct		s_max
{
	unsigned int	mlink;
	unsigned int	muid;
	unsigned int	mgid;
	unsigned int	msize;
	int				size;
	unsigned int	nblink;
	char			uid[1024];
	char			gid[1024];
	char			link[1024];
	char			right[12];
	char			mdhm[13];
	char			year[4];
	unsigned int	nbblock;
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
void				ft_exit(void);
char				*ft_strjoin(char *s1, char *s2);
void				btree_apply_infix(t_btree *root, char flag[128]);
void				ft_insert(t_btree **btree, t_btree *new, char flag[128]);
void				ft_printfinfo(struct stat *info);
int					ft_strcmp(char *s1, char *s2);
int					ft_rec_start(char *init, char flag[128]);
int					ft_dont_go(t_btree *btree, char flag[128]);
char				ft_getfiletype(mode_t x);
void				btree_insert_d(t_btree **root, t_btree *new,
					char flag[128]);
void				btree_insert_u(t_btree **root, t_btree *new,
					char flag[128]);
void				btree_insert(t_btree **root, t_btree *new,
					char flag[128]);
void				btree_insert_t(t_btree **root, t_btree *new,
					char flag[128]);
void				btree_insert_um(t_btree **root, t_btree *new,
					char flag[128]);
void				btree_insert_f(t_btree **root, t_btree *new,
					char flag[128]);
void				btree_insert_sm(t_btree **root, t_btree *new,
					char flag[128]);
char				*ft_strcpy(char *dst, char *src);
void				ft_testmax(t_max *max, t_btree *new);
void				ft_init_max(t_max *max);
void				ft_itoa(long long value, char str[1024]);
t_btree				*ft_create_spe(char *init);
int					ft_draw_l(t_btree *root, char flag[128], t_max *max);

#endif
