/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cv_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:25:45 by awyart            #+#    #+#             */
/*   Updated: 2017/05/17 19:43:35 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_c(t_flag *flag, char c)
{
	if (flag->width == INT_MIN)
		flag->width = 0;
	if (flag->width < 0)
	{
		flag->flags['-'] = 1;
		flag->width = -(flag->width);
	}
	if (flag->flags['-'])
		flag->flags['0'] = 0;
	if (!(flag->flags['-']) && !(flag->flags['0']))
	{
		ft_putnchar(flag->width - 1, ' ');
		flag->count += ft_pops(flag->width - 1);
	}
	if (flag->flags['0'])
	{
		ft_putnchar(flag->width - 1, '0');
		flag->count += ft_pops(flag->width - 1);
	}
	ft_putchar(c);
	(flag->count)++;
	if (flag->flags['-'] && (flag->count += ft_pops(flag->width - 1)))
		ft_putnchar(flag->width - 1, ' ');
}

void	conv_c(t_flag *flag, va_list *ap, char content[BUFF_SIZE])
{
	int s;

	s = va_arg(*ap, int);
	flag->len = 1;
	content[0] = 'c';
	if (flag->flags['l'] >= 1)
		ft_cm(flag, s);
	else
	{
		ft_c(flag, (char)s);
	}
}
