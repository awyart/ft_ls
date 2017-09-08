/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cv_cm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:25:47 by awyart            #+#    #+#             */
/*   Updated: 2017/05/23 10:38:41 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	ft_cm(t_flag *flag, int s)
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
	flag->count += ft_putchar_unicode(s);
	if (flag->flags['-'] && (flag->count += ft_pops(flag->width - 1)))
		ft_putnchar(flag->width - 1, ' ');
}

void	conv_cm(t_flag *flag, va_list *ap, char content[BUFF_SIZE])
{
	int	s;

	s = va_arg(*ap, int);
	content[0] = (char)s;
	if (MB_CUR_MAX == 1 && s < 256)
		ft_c(flag, (char)s);
	else if (MB_CUR_MAX == 1)
		return ;
	else
	{
		flag->len = 2;
		ft_cm(flag, s);
	}
}
