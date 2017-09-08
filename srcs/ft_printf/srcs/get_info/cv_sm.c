/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cv_sm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:41:19 by awyart            #+#    #+#             */
/*   Updated: 2017/05/23 11:38:38 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

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

static int	ft_check_string(int *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] > 255)
			return (0);
	}
	return (1);
}

static int	ft_charlen_unicode(wchar_t a)
{
	unsigned int i;

	i = ft_countbits(a);
	if (i < 8)
		return (1);
	else if (i < 12)
		return (2);
	else if (i < 18)
		return (3);
	else if (i < 22)
		return (4);
	return (0);
}

void		ft_sm(t_flag *flag, wchar_t *content)
{
	int i;
	int j;

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
	j = -1;
	while ((j += ft_charlen_unicode(content[++i])) < flag->len)
		flag->count += ft_putchar_unicode(content[i]);
	if ((flag->flags['-'])
		&& (flag->count += ft_pops(flag->width - flag->len)))
		ft_putnchar(flag->width - flag->len, ' ');
}

void		conv_sm(t_flag *flag, va_list *ap, char content[BUFF_SIZE])
{
	wchar_t	*s;

	s = va_arg(*ap, wchar_t *);
	if (s == NULL)
	{
		AH = "(null)";
		flag->len = ft_strlen(AH);
		ft_s(flag, AH);
		return ;
	}
	else
		flag->len = ft_strlen_unicode(s);
	if (MB_CUR_MAX == 1 && ft_check_string(s) == 1)
	{
		content = (char *)s;
		ft_s(flag, content);
	}
	else if (MB_CUR_MAX == 1)
		return ;
	else
		ft_sm(flag, s);
}
