/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cv_dm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 13:14:55 by awyart            #+#    #+#             */
/*   Updated: 2017/05/16 17:00:17 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_dm(t_flag *flag, va_list *ap, char content[BUFF_SIZE])
{
	if (flag->flags['l'] == 1)
		ft_itoa((LL)va_arg(*ap, long), AH);
	else if (flag->flags['l'] == 2)
		ft_itoa(va_arg(*ap, LL), AH);
	else if (flag->flags['h'] == 1)
		ft_itoa((LL)va_arg(*ap, int), AH);
	else if (flag->flags['h'] == 2)
		ft_itoa((LL)va_arg(*ap, int), AH);
	else if (flag->flags['j'] == 1)
		ft_itoa((LL)va_arg(*ap, intmax_t), AH);
	else if (flag->flags['z'] == 1)
		ft_itoa((LL)va_arg(*ap, size_t), AH);
	else
		ft_itoa((LL)va_arg(*ap, long), AH);
	if (AH[0] == '0' && AH[1] == 0 && flag->precision != INT_MIN)
		AH[0] = 0;
	flag->len = ft_strlen(AH);
	ft_d(flag, content);
}
