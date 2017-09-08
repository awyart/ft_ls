/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cv_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:25:50 by awyart            #+#    #+#             */
/*   Updated: 2017/05/16 15:27:43 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_b(t_flag *flag, va_list *ap, char content[BUFF_SIZE])
{
	if (flag->flags['l'] == 1)
		ft_itoab_ll((ULL)va_arg(*ap, long), 2, AH);
	else if (flag->flags['l'] == 2)
		ft_itoab_ll((ULL)va_arg(*ap, LL), 2, AH);
	else if (flag->flags['h'] == 1)
		ft_itoab_ll((ULL)(short)va_arg(*ap, int), 2, AH);
	else if (flag->flags['h'] == 2)
		ft_itoab_ll((ULL)(char)va_arg(*ap, int), 2, AH);
	else if (flag->flags['j'] == 1)
		ft_itoab_ll((ULL)va_arg(*ap, intmax_t), 2, AH);
	else if (flag->flags['z'] == 1)
		ft_itoab_ll((ULL)va_arg(*ap, size_t), 2, AH);
	else
		ft_itoab_ll((ULL)va_arg(*ap, int), 2, AH);
	flag->len = ft_strlen(AH);
	ft_u(flag, content);
}

void	conv_bm(t_flag *flag, va_list *ap, char content[BUFF_SIZE])
{
	if (flag->flags['l'] == 1)
		ft_itoab_ll((ULL)va_arg(*ap, long), 2, AH);
	else if (flag->flags['l'] == 2)
		ft_itoab_ll((ULL)va_arg(*ap, LL), 2, AH);
	else if (flag->flags['h'] == 1)
		ft_itoab_ll((ULL)(short)va_arg(*ap, int), 2, AH);
	else if (flag->flags['h'] == 2)
		ft_itoab_ll((ULL)(char)va_arg(*ap, int), 2, AH);
	else if (flag->flags['j'] == 1)
		ft_itoab_ll((ULL)va_arg(*ap, intmax_t), 2, AH);
	else if (flag->flags['z'] == 1)
		ft_itoab_ll((ULL)va_arg(*ap, size_t), 2, AH);
	else
		ft_itoab_ll((ULL)va_arg(*ap, long), 2, AH);
	if (AH[0] == '0' && AH[1] == 0 && (flag->flags['#'] || flag->precision)
			&& (flag->flags['#'] = 0))
		AH[0] = 0;
	flag->len = ft_strlen(AH);
	ft_u(flag, content);
}
