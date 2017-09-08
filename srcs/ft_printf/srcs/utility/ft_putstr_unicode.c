/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_unicode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:26:54 by awyart            #+#    #+#             */
/*   Updated: 2017/05/09 14:27:01 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_unicode(char const *s)
{
	size_t	i;

	i = 0;
	if (!(s == NULL))
		while (s[i] != '\0')
		{
			ft_putchar_unicode(s[i]);
			i++;
		}
}
