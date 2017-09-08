/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cv_fm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 18:35:33 by awyart            #+#    #+#             */
/*   Updated: 2017/05/23 11:38:01 by awyart           ###   ########.fr       */
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

void		ft_f(t_flag *flag, char content[BUFF_SIZE], char ct[BUFF_SIZE])
{
	int		sign;
	size_t	i;
	int		pstr;
	int		n;

	ft_begin(flag, &sign, &pstr, content);
	n = ft_form_str(flag, sign, pstr, content);
	ft_manage_sign(flag, n, sign);
	i = -1;
	while (++i < ft_strlen(AH) - pstr && (flag->count += 1))
		ft_putchar(AH[pstr + i]);
	if (flag->precision != 0)
	{
		if (ft_strlen(ct) > 0 && (flag->count += 1))
			ft_putchar('.');
		i = -1;
		while (++i < ft_strlen(ct) && (flag->count += 1))
			ft_putchar(ct[i]);
	}
	if (flag->flags['-'])
	{
		ft_putnchar(flag->width - n, ' ');
		flag->count += ft_pops(flag->width - n);
	}
}

void		conv_fm(t_flag *flag, va_list *ap, char content[BUFF_SIZE])
{
	long double		nb;
	int				i;
	char			ct[BUFF_SIZE];

	if (flag->precision < 0)
		flag->precision = 6;
	if (flag->precision > 16)
		flag->precision = 16;
	nb = va_arg(*ap, long double);
	ft_itoab_l(ft_ent_m(nb), 10, AH);
	nb = nb - (long double)ft_ent_m(nb);
	i = -1;
	while (++i < flag->precision)
		nb *= 10.;
	i = -1;
	while (++i < BUFF_SIZE)
		ct[i] = '\0';
	if (nb >= 0)
		ft_itoab_l(ft_ent(nb), 10, ct);
	else
		ft_itoab_l(ft_ent(-1 * nb), 10, ct);
	flag->len = ft_strlen(AH) + ft_strlen(ct) + 1;
	ft_f(flag, AH, ct);
}
