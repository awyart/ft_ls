/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cv_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:54:27 by awyart            #+#    #+#             */
/*   Updated: 2017/05/23 11:08:15 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	assign_long(t_flag *flag, long *a)
{
	long *nb;

	nb = a;
	*nb = flag->count;
}

void	conv_nm(t_flag *flag, va_list *ap, char content[BUFF_SIZE])
{
	content[0] = 'n';
	assign_long(flag, va_arg(*ap, long *));
}
