/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cv_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:49:56 by awyart            #+#    #+#             */
/*   Updated: 2017/05/17 16:32:49 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_begin(t_flag *flag, int *sign, int *pstr,
	char content[BUFF_SIZE])
{
	*pstr = 0;
	if (flag->width == INT_MIN)
		flag->width = 0;
	if (flag->width < 0)
	{
		flag->flags['-'] = 1;
		flag->width = -(flag->width);
	}
	if (flag->precision >= 0)
		flag->flags['0'] = 0;
	if (flag->len > 0 && (AH[*pstr] == '-' || AH[*pstr] == '+'))
	{
		*sign = AH[*pstr];
		(flag->len)--;
		(*pstr)++;
	}
	else if (flag->flags['+'])
		*sign = '+';
	else if (flag->flags[' '])
		*sign = ' ';
	else
		*sign = 0;
}

static int	ft_form_str(t_flag *flag, int sign, int pstr,
	char content[BUFF_SIZE])
{
	int	n;

	if (flag->precision < 0)
		flag->precision = 1;
	if (flag->len < flag->precision)
		n = flag->precision;
	else if (flag->precision == 0 && flag->len == 1 && AH[pstr] == '0')
		n = 0;
	else
		n = flag->len;
	if (sign)
		(n)++;
	return (n);
}

static void	ft_manage_sign(t_flag *flag, int n, int sign)
{
	if (flag->flags['-'] || flag->flags['0'])
	{
		if (sign && (flag->count += 1))
			ft_putchar(sign);
		if (!(flag->flags['-']) && (flag->count += ft_pops(flag->width - n)))
			ft_putnchar(flag->width - n, '0');
	}
	else
	{
		ft_putnchar(flag->width - n, ' ');
		flag->count += ft_pops(flag->width - n);
		if (sign && (flag->count += 1))
			ft_putchar(sign);
	}
}

void		ft_d(t_flag *flag, char content[BUFF_SIZE])
{
	int sign;
	int i;
	int pstr;
	int n;

	ft_begin(flag, &sign, &pstr, content);
	n = ft_form_str(flag, sign, pstr, content);
	ft_manage_sign(flag, n, sign);
	ft_putnchar(flag->precision - flag->len, '0');
	flag->count += ft_pops(flag->precision - flag->len);
	i = -1;
	while (++i < flag->len)
	{
		ft_putchar(AH[pstr++]);
		(flag->count)++;
	}
	if (flag->flags['-'])
	{
		ft_putnchar(flag->width - n, ' ');
		flag->count += ft_pops(flag->width - n);
	}
}

void		conv_d(t_flag *flag, va_list *ap, char content[BUFF_SIZE])
{
	if (flag->flags['l'] == 1)
		ft_itoa((LL)va_arg(*ap, long), AH);
	else if (flag->flags['l'] == 2)
		ft_itoa(va_arg(*ap, LL), AH);
	else if (flag->flags['h'] == 1)
		ft_itoa((LL)(short)va_arg(*ap, int), AH);
	else if (flag->flags['h'] == 2)
		ft_itoa((LL)(char)va_arg(*ap, int), AH);
	else if (flag->flags['j'] == 1)
		ft_itoa((LL)va_arg(*ap, intmax_t), AH);
	else if (flag->flags['z'] == 1)
		ft_itoa((LL)va_arg(*ap, size_t), AH);
	else
		ft_itoa((LL)va_arg(*ap, int), AH);
	if (AH[0] == '0' && AH[1] == 0 && flag->precision != INT_MIN)
		AH[0] = 0;
	flag->len = ft_strlen(AH);
	ft_d(flag, content);
}
