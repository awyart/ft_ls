/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 19:44:15 by awyart            #+#    #+#             */
/*   Updated: 2017/05/23 11:09:25 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_ent(double x)
{
	return ((long long)(x + 0.5));
}

long long	ft_ent_m(double x)
{
	return ((long long)(x));
}

long long	ft_ent_l(long double x)
{
	return ((long long)(x + 0.5));
}

long long	ft_ent_ml(long double x)
{
	return ((long long)(x));
}
