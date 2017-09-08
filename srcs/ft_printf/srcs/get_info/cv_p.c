/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cv_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:43:40 by awyart            #+#    #+#             */
/*   Updated: 2017/05/23 11:38:18 by awyart           ###   ########.fr       */
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
	if (flag->flags['-'] || flag->flags['0'])
	{
		ft_putstr("0x");
		if (!(flag->flags['-']) && (flag->count += ft_pops(flag->width - n)))
			ft_putnchar(flag->width - n, '0');
	}
	else
	{
		ft_putnchar(flag->width - n, ' ');
		ft_putstr("0x");
		flag->count += ft_pops(flag->width - n);
	}
}

void		ft_p(t_flag *flag, char content[BUFF_SIZE])
{
	int i;
	int n;

	ft_begin(flag);
	n = ft_form_str(flag, content);
	ft_manage_sign(flag, n);
	ft_putnchar(flag->precision - flag->len, '0');
	flag->count += 2 + ft_pops(flag->precision - flag->len);
	i = -1;
	while (++i < flag->len)
	{
		ft_putchar(AH[i]);
		(flag->count)++;
	}
	if (flag->flags['-'])
	{
		ft_putnchar(flag->width - n, ' ');
		flag->count += ft_pops(flag->width - n);
	}
}

void		conv_p(t_flag *flag, va_list *ap, char content[BUFF_SIZE])
{
	void *test;

	test = va_arg(*ap, void *);
	if (!(flag->width == INT_MIN))
		flag->width -= 2;
	if (test == NULL)
	{
		flag->len = 0;
		AH[0] = 0;
	}
	else
	{
		ft_itoab_ll((ULL)test, 16, AH);
		ft_down(AH);
		flag->len = ft_strlen(AH);
	}
	ft_p(flag, content);
}
