/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:16:22 by awyart            #+#    #+#             */
/*   Updated: 2017/09/19 15:09:11 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_usage(char c)
{
	PRINTF("ls: illegal option: %c\n", c);
	PRINTF("usage: ./ft_ls [%s] [file ...]\n", OPTIONS);
	exit(0);
}

void	ft_get_option(char *str, char flag[128])
{
	int i;

	i = 1;
	while (str[i] != '\0')
	{
		if (ft_strchr(OPTIONS, str[i]) == NULL)
			ft_usage(str[i]);
		else
		{
			flag[(int)str[i]] = 1;
		}
		i++;
	}
	if (flag['f'] == 1)
		flag['a'] = 1;
	if (flag['L'] == 1)
		flag['P'] = 0;
	if (flag['G'] == 1)
		flag['l'] = 1;
	if (flag['P'] == 1)
		flag['L'] = 0;
}
