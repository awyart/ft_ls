/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 11:47:25 by awyart            #+#    #+#             */
/*   Updated: 2017/05/23 11:53:48 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "convert.h"

static void		ft_get_width(t_flag *flag, va_list *ap, char *str, int *i)
{
	int n;

	n = INT_MIN;
	if (str[*i] == '*' && (flag->flags['*'] = 1))
	{
		n = va_arg(*ap, int);
		(*i)++;
		if (ft_isdigit(str[*i]))
			n = 0;
		while (ft_isdigit(str[*i]))
			n = ((int)str[(*i)++] - '0') + n * 10;
	}
	else
	{
		while (ft_isdigit(str[*i]))
			n = ((int)str[(*i)++] - '0') + n * 10;
		if (str[*i] == '*' && (flag->flags['*'] = 1))
		{
			n = va_arg(*ap, int);
			(*i)++;
		}
	}
	flag->width = n;
}

static void		ft_get_precision(t_flag *flag, va_list *ap, char *str, int *i)
{
	int n;

	n = 0;
	if (str[*i] == '.' && (*i += 1))
	{
		if (str[*i] == '*' || ft_isdigit(str[*i]))
		{
			if (str[*i] == '*' && (flag->flags['*'] += 2))
			{
				n = va_arg(*ap, int);
				if (ft_isdigit(str[(*i)++]))
					n = 0;
				while (ft_isdigit(str[*i]))
					n = ((int)str[(*i)++] - '0') + n * 10;
			}
			else
			{
				while (ft_isdigit(str[*i]))
					n = (str[(*i)++] - '0') + n * 10;
				if (str[*i] == '*' && (flag->flags['*'] += 2) && (*i += 1))
					n = va_arg(*ap, int);
			}
		}
		flag->precision = n;
	}
}

static void		ft_get_modif(t_flag *flag, char *test, char *str, int *i)
{
	while (ft_strchr(test, str[*i]))
		(flag->flags[(int)str[(*i)++]]) += 1;
}

static int		ft_get_content(t_flag *flag, va_list *ap,
	char content[BUFF_SIZE])
{
	size_t		j;
	t_conv		*test;

	test = g_conv;
	j = -1;
	while (++j < NB_OPTIONS)
	{
		if (flag->flag_type == test[j].status[0])
		{
			test[j].f(flag, ap, content);
			return (1);
		}
	}
	return (-1);
}

int				ft_get_flag(char *format, t_flag *flag, va_list *ap,
	char content[BUFF_SIZE])
{
	int		i;

	i = 1;
	if (format[1] == '\0')
		return (-1);
	ft_get_modif(flag, FLAG1, format, &i);
	ft_get_width(flag, ap, format, &i);
	ft_get_precision(flag, ap, format, &i);
	ft_get_modif(flag, FLAG2, format, &i);
	if (ft_strchr(OPTIONS, format[i]) == NULL)
	{
		ft_c(flag, format[i]);
		flag->flag_len = i;
		return (-1);
	}
	flag->flag_len = i;
	flag->flag_type = format[i];
	ft_get_content(flag, ap, content);
	return (1);
}
