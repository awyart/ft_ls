/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cv_n.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:54:27 by awyart            #+#    #+#             */
/*   Updated: 2017/05/17 23:24:15 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	assign_char(t_flag *flag, char *a)
{
	char *nb;

	nb = a;
	*nb = flag->count;
}

static void	assign_short(t_flag *flag, short *a)
{
	short *nb;

	nb = a;
	*nb = flag->count;
}

static void	assign_intmax(t_flag *flag, intmax_t *a)
{
	intmax_t *nb;

	nb = a;
	*nb = flag->count;
}

static void	assign_longlong(t_flag *flag, long long *a)
{
	long long *nb;

	nb = a;
	*nb = flag->count;
}

void		conv_n(t_flag *flag, va_list *ap, char content[BUFF_SIZE])
{
	int *nb;

	content[0] = 'n';
	if (flag->flags['l'] == 1)
		assign_long(flag, va_arg(*ap, long *));
	else if (flag->flags['l'] == 2)
		assign_longlong(flag, va_arg(*ap, long long *));
	else if (flag->flags['h'] == 1)
		assign_short(flag, (short *)va_arg(*ap, int *));
	else if (flag->flags['h'] == 2)
		assign_char(flag, (char *)va_arg(*ap, int *));
	else if (flag->flags['j'] == 1)
		assign_intmax(flag, va_arg(*ap, intmax_t *));
	else if (flag->flags['z'] == 1)
		assign_longlong(flag, (long long *)va_arg(*ap, size_t *));
	else
	{
		nb = va_arg(*ap, int *);
		*nb = flag->count;
	}
}
