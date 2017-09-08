/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 10:49:33 by awyart            #+#    #+#             */
/*   Updated: 2017/05/23 11:42:37 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t size;

	if (s == NULL)
		return (0);
	size = 0;
	while (s[size] != '\0')
	{
		size++;
	}
	return (size);
}

size_t	ft_strlen_unicode(wchar_t *a)
{
	unsigned int i;
	unsigned int count;
	unsigned int j;

	count = 0;
	j = -1;
	while (a[++j])
	{
		i = ft_countbits(a[j]);
		if (i < 8)
			count += 1;
		else if (i < 12)
			count += 2;
		else if (i < 18)
			count += 3;
		else if (i < 22)
			count += 4;
	}
	return (count);
}
