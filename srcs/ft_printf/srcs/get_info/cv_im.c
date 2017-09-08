/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cv_im.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 23:05:27 by awyart            #+#    #+#             */
/*   Updated: 2017/05/23 11:06:37 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		conv_im(t_flag *flag, va_list *ap, char content[BUFF_SIZE])
{
	if (!(flag->width > 1 && flag->width <= 16))
		return ;
	if (flag->flags['l'] == 1)
		ft_itoab_ll((ULL)va_arg(*ap, unsigned long), flag->width, AH);
	else if (flag->flags['l'] == 2)
		ft_itoab_ll(va_arg(*ap, ULL), flag->width, AH);
	else if (flag->flags['h'] == 1)
		ft_itoab_ll((ULL)(unsigned short)
						va_arg(*ap, unsigned int), flag->width, AH);
	else if (flag->flags['h'] == 2)
		ft_itoab_ll((ULL)(unsigned char)
					va_arg(*ap, unsigned int), flag->width, AH);
	else if (flag->flags['j'] == 1)
		ft_itoab_ll((ULL)va_arg(*ap, uintmax_t), flag->width, AH);
	else if (flag->flags['z'] == 1)
		ft_itoab_ll((ULL)va_arg(*ap, size_t), flag->width, AH);
	else
		ft_itoab_ll((ULL)va_arg(*ap, unsigned int), 10, AH);
	if (AH[0] == '0' && AH[1] == 0 && (flag->flags['#'] ||
		flag->precision != INT_MIN) && (flag->flags['#'] = 0))
		AH[0] = 0;
	flag->len = ft_strlen(AH);
	flag->width = INT_MIN;
	ft_x(flag, content);
}
