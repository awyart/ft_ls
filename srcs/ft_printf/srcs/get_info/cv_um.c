/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cv_um.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:09:50 by awyart            #+#    #+#             */
/*   Updated: 2017/05/16 17:01:37 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_um(t_flag *flag, va_list *ap, char content[BUFF_SIZE])
{
	flag->flags['+'] = 0;
	flag->flags[' '] = 0;
	if (flag->flags['l'] == 1)
		ft_itoab_ll((ULL)va_arg(*ap, unsigned long), 10, AH);
	else if (flag->flags['l'] == 2)
		ft_itoab_ll((ULL)va_arg(*ap, ULL), 10, AH);
	else if (flag->flags['h'] == 1)
		ft_itoab_ll((ULL)va_arg(*ap, unsigned long), 10, AH);
	else if (flag->flags['h'] == 2)
		ft_itoab_ll((ULL)va_arg(*ap, unsigned long), 10, AH);
	else if (flag->flags['j'] == 1)
		ft_itoab_ll((ULL)va_arg(*ap, uintmax_t), 10, AH);
	else if (flag->flags['z'] == 1)
		ft_itoab_ll((ULL)va_arg(*ap, size_t), 10, AH);
	else
		ft_itoab_ll((ULL)va_arg(*ap, unsigned long), 10, AH);
	if (AH[0] == '0' && AH[1] == 0 && (flag->flags['#'] || flag->precision)
			&& (flag->flags['#'] = 0))
		AH[0] = 0;
	flag->len = ft_strlen(AH);
	ft_u(flag, content);
}
