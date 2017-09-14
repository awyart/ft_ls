/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 14:45:12 by awyart            #+#    #+#             */
/*   Updated: 2017/09/14 18:09:11 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void btree_insert_f(t_btree **root, t_btree *new, char flag[128])
{

	if (!(*root))
	{
		*root = new;
	}
	else
	{
		btree_insert_f(&((*root)->left), new, flag);
	}
}