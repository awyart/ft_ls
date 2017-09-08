/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:49:06 by awyart            #+#    #+#             */
/*   Updated: 2017/05/16 13:17:55 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static int	ft_put_long(long long *value)
{
	if (*value < 0)
	{
		*value = -(*value);
		return (1);
	}
	return (0);
}

static int	ft_put_size(long long value)
{
	int size;

	size = 0;
	if (value == 0)
		size = 1;
	else
		while (value != 0)
		{
			value = value / 10;
			size++;
		}
	return (size);
}

static void	ft_handle_llmax(char *str, long long value, int size)
{
	str[size + 1] = '\0';
	str[size] = "0123456789"[-(value % 10)];
	value = value / 10;
	value = -value;
	while (--size >= 0)
	{
		str[size] = "0123456789"[value % 10];
		value /= 10;
	}
	str[0] = '-';
}

void		ft_itoa(long long value, char str[BUFF_SIZE])
{
	int			neg;
	int			size;

	size = ft_put_size(value);
	if (value == LLONG_MIN)
	{
		ft_handle_llmax(str, value, size);
		return ;
	}
	neg = ft_put_long(&value);
	size = size + neg;
	str[size] = '\0';
	while (--size >= 0)
	{
		str[size] = "0123456789"[value % 10];
		value = value / 10;
	}
	if (neg)
		str[0] = '-';
}
