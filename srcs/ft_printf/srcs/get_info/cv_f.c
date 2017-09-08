/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cv_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:37:17 by awyart            #+#    #+#             */
/*   Updated: 2017/05/23 10:56:05 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_douille(t_flag *flag)
{
	if (flag->precision < 0)
		flag->precision = 6;
	if (flag->precision > 16)
		flag->precision = 16;
}

void		conv_f(t_flag *flag, va_list *ap, char content[BUFF_SIZE])
{
	double		nb;
	int			i;
	char		ct[BUFF_SIZE];

	if (flag->flags['L'] == 1)
	{
		conv_fm(flag, ap, content);
		return ;
	}
	ft_douille(flag);
	nb = va_arg(*ap, double);
	ft_itoab_l(ft_ent_m(nb), 10, AH);
	nb = nb - (double)ft_ent_m(nb);
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
