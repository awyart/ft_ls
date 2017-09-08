/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cv_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:07:25 by awyart            #+#    #+#             */
/*   Updated: 2017/05/19 18:34:54 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_begin(t_flag *flag)
{
	if (flag->width == INT_MIN)
		flag->width = 0;
	if (flag->width < 0)
	{
		flag->flags['-'] = 1;
		flag->width = -(flag->width);
	}
	if (flag->precision >= 0)
		flag->flags['0'] = 0;
}

static int	ft_form_str(t_flag *flag, char content[BUFF_SIZE])
{
	int	n;

	if (flag->precision < 0)
		flag->precision = 1;
	if (flag->len < flag->precision)
		n = flag->precision;
	else if (flag->precision == 0 && flag->len == 1 && AH[0] == '0')
		n = 0;
	else
		n = flag->len;
	return (n);
}

static void	ft_manage_sign(t_flag *flag, int n)
{
	if (flag->flags['#'])
		flag->width--;
	if (flag->flags['-'] || flag->flags['0'])
	{
		if (!(flag->flags['-']) && (flag->count += ft_pops(flag->width - n)))
			ft_putnchar(flag->width - n, '0');
	}
	else
	{
		ft_putnchar(flag->width - n, ' ');
		flag->count += ft_pops(flag->width - n);
	}
}

void		ft_o(t_flag *flag, char content[BUFF_SIZE])
{
	int i;
	int n;

	ft_begin(flag);
	n = ft_form_str(flag, content);
	ft_manage_sign(flag, n);
	ft_putnchar(flag->precision - flag->len, '0');
	flag->count += ft_pops(flag->precision - flag->len);
	i = -1;
	if (flag->flags['#'] && (flag->precision - flag->len) <= 0)
	{
		ft_putchar('0');
		(flag->count)++;
	}
	while (++i < flag->len && ((flag->count += 1)))
		ft_putchar(AH[i]);
	if (flag->flags['-'])
	{
		ft_putnchar(flag->width - n, ' ');
		flag->count += ft_pops(flag->width - n);
	}
}

void		conv_o(t_flag *flag, va_list *ap, char content[BUFF_SIZE])
{
	flag->flags['+'] = 0;
	flag->flags[' '] = 0;
	if (flag->flags['l'] == 1)
		ft_itoab_ll((ULL)va_arg(*ap, unsigned long), 8, AH);
	else if (flag->flags['l'] == 2)
		ft_itoab_ll(va_arg(*ap, ULL), 8, AH);
	else if (flag->flags['h'] == 1)
		ft_itoab_ll((ULL)
			(unsigned short)va_arg(*ap, unsigned int), 8, AH);
	else if (flag->flags['h'] == 2)
		ft_itoab_ll((ULL)(unsigned char)va_arg(*ap, unsigned int), 8, AH);
	else if (flag->flags['j'] == 1)
		ft_itoab_ll((ULL)va_arg(*ap, uintmax_t), 8, AH);
	else if (flag->flags['z'] == 1)
		ft_itoab_ll((ULL)va_arg(*ap, size_t), 8, AH);
	else
		ft_itoab_ll((ULL)va_arg(*ap, unsigned int), 8, AH);
	if (AH[0] == '0' && AH[1] == 0
			&& (flag->flags['#'] || flag->precision != INT_MIN))
		AH[0] = 0;
	flag->len = ft_strlen(AH);
	ft_o(flag, AH);
}
