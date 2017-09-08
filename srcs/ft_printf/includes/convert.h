/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:33:19 by awyart            #+#    #+#             */
/*   Updated: 2017/05/23 10:19:51 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H

t_conv	g_conv[] =
{
	{"s", &conv_s},
	{"S", &conv_sm},
	{"p", &conv_p},
	{"d", &conv_d},
	{"D", &conv_dm},
	{"i", &conv_d},
	{"o", &conv_o},
	{"O", &conv_om},
	{"u", &conv_u},
	{"U", &conv_um},
	{"x", &conv_x},
	{"X", &conv_xm},
	{"c", &conv_c},
	{"C", &conv_cm},
	{"b", &conv_b},
	{"B", &conv_bm},
	{"I", &conv_im},
	{"n", &conv_n},
	{"f", &conv_f},
	{"F", &conv_f},
	{"%", &conv_per}
};

#endif
