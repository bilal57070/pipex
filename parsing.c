/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirio <mirio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:02:00 by mirio             #+#    #+#             */
/*   Updated: 2024/01/05 23:04:48 by mirio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	takeav(char **av, t_stru *stru)
{
	int	i;
	int	j;
	int	k;
	int	lenav;

	i = 0;
	k = 0;
	countin(stru, av);
	stru->sto = malloc(sizeof(char *) * (stru->in + stru->out + 1));
	if (!stru->sto)
		exit(1);
	while (av[++i])
	{
		j = 0;
        //lenav = ft_strlen(av[i]);
        //ft_printf("lenav : %d\n", lenav);
        //if (lenav > 1)
		stru->sto[k] = ft_strdup(av[i]);
        ft_printf("sto : %s\n", stru->sto[k]);
		k++;
        //else
	}
	stru->sto[k] = 0;
    printab(stru);
}

void	countin(t_stru *stru, char **av)
{
    int i;
    int j;

    i = 0;
	stru->in = 0;
	stru->out = 0;
    while (av[++i])
    {
        stru->out++;
        j = -1;
        while (av[i][++j])
            stru->in++;
    }
}
// utiliser la commande which en shell qui permet de savoir si c bien une commande en shell
// mais bon comment faire ??
// belek tu fais un processus fils qui execute le which et un pipe qui sort vers ta fonction.

void	printab(t_stru *stru)
{
    int i;

    i = -1;
    while (stru->sto[++i])
        ft_printf("str = %s\n", stru->sto[i]);
}

void	testfile(char **av)
{
    if (open(av[1], O_DIRECTORY) != -1)
    {
        ft_printf("erreur : probleme fichier (dossier)\n");
        exit(1);
    }
    if (open(av[4], O_DIRECTORY) != -1)
    {
        ft_printf("erreur : probleme fichier (dossier)\n");
        exit(1);
    }
}
