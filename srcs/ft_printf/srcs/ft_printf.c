/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 21:24:39 by awyart            #+#    #+#             */
/*   Updated: 2017/05/17 17:17:31 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_reset(t_flag *flag, char content[BUFF_SIZE])
{
	int i;

	i = -1;
	while (++i < BUFF_SIZE)
		content[i] = '\0';
	i = -1;
	while (++i < 128)
		flag->flags[i] = 0;
	flag->len = 0;
	flag->nb_type = 0;
	flag->flag_type = 0;
	flag->width = INT_MIN;
	flag->precision = INT_MIN;
	flag->flag_len = 0;
}

int			ft_printf(char *format, ...)
{
	va_list	ap;
	int		i;
	t_flag	flag;
	char	content[BUFF_SIZE];

	i = -1;
	flag.count = 0;
	va_start(ap, format);
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			ft_reset(&flag, content);
			ft_get_flag(format + i, &flag, (va_list *)ap, content);
			i = i + flag.flag_len;
		}
		else if ((flag.count += 1))
			ft_putchar(format[i]);
	}
	va_end(ap);
	return (flag.count);
}
