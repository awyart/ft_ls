/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:16:22 by awyart            #+#    #+#             */
/*   Updated: 2017/09/11 14:02:36 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void 	ft_usage(char c)
{
	ft_printf("ls: illegal option: %c\n", c);
	ft_printf("usage: ./ft_ls [%s] [file ...]", OPTIONS);
	exit(0);
}

void 	ft_get_option(char *str, char flag[128])
{
	int i;

	i = 1;
	while (str[i])
	{
		if (ft_strchr(OPTIONS, str[i]) == NULL)
			ft_usage(str[i]);
		else
			flag[str[i]] = 1;
		i++;
	}
	if (flag['f'] == 1)
		flag['a'] = 1;
}
