/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cv_om.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:07:35 by awyart            #+#    #+#             */
/*   Updated: 2017/05/17 15:03:39 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_om(t_flag *flag, va_list *ap, char content[BUFF_SIZE])
{
	flag->flags['+'] = 0;
	flag->flags[' '] = 0;
	if (flag->flags['l'] == 1)
		ft_itoab_ll((ULL)va_arg(*ap, unsigned long), 8, AH);
	else if (flag->flags['l'] == 2)
		ft_itoab_ll(va_arg(*ap, ULL), 8, AH);
	else if (flag->flags['h'] == 1)
		ft_itoab_ll((ULL)va_arg(*ap, unsigned int), 8, AH);
	else if (flag->flags['h'] == 2)
		ft_itoab_ll((ULL)(unsigned short)va_arg(*ap, unsigned int), 8, AH);
	else if (flag->flags['j'] == 1)
		ft_itoab_ll((ULL)va_arg(*ap, uintmax_t), 8, AH);
	else if (flag->flags['z'] == 1)
		ft_itoab_ll((ULL)va_arg(*ap, size_t), 8, AH);
	else
		ft_itoab_ll((ULL)va_arg(*ap, unsigned long), 8, AH);
	if (AH[0] == '0' && AH[1] == 0
			&& (flag->flags['#'] || flag->precision != INT_MIN))
		AH[0] = 0;
	flag->len = ft_strlen(AH);
	ft_o(flag, content);
}
