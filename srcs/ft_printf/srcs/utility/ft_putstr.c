/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:53:49 by awyart            #+#    #+#             */
/*   Updated: 2017/09/19 12:06:59 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_stlen(const char *s)
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

void			ft_putstr(char const *str)
{
	if (!(str == NULL))
		write(1, str, ft_stlen(str));
}
