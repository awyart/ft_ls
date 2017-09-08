/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_unicode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:03:20 by awyart            #+#    #+#             */
/*   Updated: 2017/05/23 11:42:58 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_countbits(unsigned int c)
{
	unsigned int	i;
	int				count;

	i = 0x80000000;
	if (c == 0)
		return (0);
	while (!(i & c))
		i >>= 1;
	count = 0;
	while (i > 0)
	{
		count++;
		i >>= 1;
	}
	return (count);
}

static void		ft_print_3(unsigned char letter[4], unsigned int c)
{
	letter[0] = 0xE0 | (c >> 12);
	letter[1] = 0x80 | (0x3F & c >> 6);
	letter[2] = 0x80 | (0x3F & c);
	write(1, letter, 3);
}

static int		ft_print_4(unsigned char letter[4], unsigned int c)
{
	letter[0] = 0xF0 | (c >> 18);
	letter[1] = 0x80 | (0x3F & c >> 12);
	letter[2] = 0x80 | (0x3F & c >> 6);
	letter[3] = 0x80 | (0x3F & c);
	write(1, letter, 4);
	return (1);
}

int				ft_putchar_unicode(unsigned int c)
{
	unsigned int	i;
	unsigned char	letter[4];

	i = ft_countbits(c);
	if (i < 8)
	{
		letter[0] = c;
		write(1, letter, 1);
		return (1);
	}
	else if (i < 12)
	{
		letter[0] = 0xC0 | (0x1F & c >> 6);
		letter[1] = 0x80 | (0x3F & c);
		write(1, letter, 2);
		return (2);
	}
	else if (i < 18)
	{
		ft_print_3(letter, c);
		return (3);
	}
	else if ((i < 22) && (ft_print_4(letter, c)))
		return (4);
	return (0);
}
