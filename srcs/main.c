/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 11:22:29 by awyart            #+#    #+#             */
/*   Updated: 2017/09/08 16:20:00 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int ft_rec_start(void *ret, DIR *dir)
{
	if ((ret = readdir(dir)))
	{
		/*creer l'arbre binaire*/
		/*afficher l'arbre binaire*/
		ft_rec_start(ret)
	}
	/*passer au fichier suivant*/
	return (0);
}

int ft_start(char *init, char flag[128])
{
	DIR *dir;

	dir = opendir(init);
	if (dir == NULL)
		return (0);
	while (ret = readdir(dir))
	{
		ft_printf("")
		/*afficher l'arbre binaire*/
		if (flag['R'] == 1)
			ft_rec_start(ret, dir);
	}
	closedir(dir);


}

int main(int ac, char **av)
{
	char flag[128];

	ft_printf("bonjour\n");
	if (ac == 1)
		ft_start(".", flag);

	ft_printf("aurevoir\n");
}