/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 13:45:18 by awyart            #+#    #+#             */
/*   Updated: 2017/09/12 13:22:45 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strchr(char *s, int c)
{
	size_t	size;
	char	*sch;
	size_t	i;

	sch = (char *)s;
	i = 0;
	size = ft_strlen(s);
	if (c == 0)
		return (sch + size);
	while (sch[i] != c && sch[i] != '\0')
		i++;
	if (i == size)
		return (NULL);
	return (sch + i);
}
