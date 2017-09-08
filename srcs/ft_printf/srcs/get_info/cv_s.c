/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cv_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:38:56 by awyart            #+#    #+#             */
/*   Updated: 2017/05/23 11:08:45 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_form(t_flag *flag)
{
	if (flag->width == INT_MIN)
		flag->width = 0;
	if (flag->width < 0)
	{
		flag->flags['-'] = 1;
		flag->width = -(flag->width);
	}
	if (flag->precision >= 0 && flag->precision < flag->len)
		flag->len = flag->precision;
}

void		ft_s(t_flag *flag, char content[BUFF_SIZE])
{
	int i;

	ft_form(flag);
	if (flag->len < 0)
		flag->len = 0;
	if (flag->flags['-'])
		flag->flags['0'] = 0;
	if ((!(flag->flags['-']) && (flag->flags['0'] == 0)
		&& (flag->count += ft_pops(flag->width - flag->len))))
		ft_putnchar(flag->width - flag->len, ' ');
	if (flag->flags['0'])
	{
		ft_putnchar(flag->width - flag->len, '0');
		flag->count += ft_pops(flag->width - flag->len);
	}
	i = -1;
	while (++i < flag->len && (flag->count += 1))
		ft_putchar(AH[i]);
	if ((flag->flags['-'])
		&& (flag->count += ft_pops(flag->width - flag->len)))
		ft_putnchar(flag->width - flag->len, ' ');
}

void		conv_s(t_flag *flag, va_list *ap, char content[BUFF_SIZE])
{
	if (flag->flags['l'] >= 1)
		conv_sm(flag, ap, content);
	else
	{
		AH = va_arg(*ap, char *);
		if (AH == NULL)
			AH = "(null)";
		flag->len = ft_strlen(AH);
		ft_s(flag, AH);
	}
}
