/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoab_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 15:57:57 by awyart            #+#    #+#             */
/*   Updated: 2017/05/19 21:13:32 by awyart           ###   ########.fr       */
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

static int	ft_put_size(long long value, int base)
{
	int size;

	size = 0;
	if (value == 0)
		size = 1;
	else
		while (value != 0)
		{
			value = value / base;
			size++;
		}
	return (size);
}

static void	ft_handle_llmax(char *str, long long value, int size, int base)
{
	str[size + 1] = '\0';
	str[size] = "0123456789abcdef"[-(value % base)];
	value = value / base;
	value = -value;
	while (--size >= 0)
	{
		str[size] = "0123456789"[value % base];
		value /= base;
	}
	str[0] = '-';
}

void		ft_itoab_l(long long value, int base, char str[BUFF_SIZE])
{
	int			neg;
	int			size;

	size = ft_put_size(value, base);
	if (value == LLONG_MIN)
	{
		ft_handle_llmax(str, value, size, base);
		return ;
	}
	neg = ft_put_long(&value);
	size = size + neg;
	str[size] = '\0';
	while (--size >= 0)
	{
		str[size] = "0123456789abcdef"[value % base];
		value = value / base;
	}
	if (neg)
		str[0] = '-';
}
