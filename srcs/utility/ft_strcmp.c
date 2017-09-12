/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 11:22:43 by awyart            #+#    #+#             */
/*   Updated: 2017/09/12 18:38:42 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	c1;
	unsigned char	c2;
	int				i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			break ;
	}
	c1 = (unsigned char)s1[i];
	c2 = (unsigned char)s2[i];
	return (c1 - c2);
}
