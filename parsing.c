/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:02:00 by mirio             #+#    #+#             */
/*   Updated: 2024/03/04 17:49:08 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	takeav(char **av, t_stru *stru)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	countin(stru, av);
	stru->sto = malloc(sizeof(char *) * (stru->in + stru->out + 1));
	if (!stru->sto)
		exit(1);
	while (av[++i])
	{
		stru->sto[k] = ft_strdup(av[i]);
		k++;
	}
	stru->sto[k] = 0;
}

void	countin(t_stru *stru, char **av)
{
	int	i;
	int	j;

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

void	testfile(char **av, t_stru *stru)
{
	if (access(av[1], F_OK) == -1)
	{
		free_tab(stru->path);
		ft_printf("erreur : fichier existe pas\n");
		exit(1);
	}
	if (access(av[4], F_OK) == -1)
	{
		open(av[4], O_CREAT | O_WRONLY | O_TRUNC);
	}
	if (open(av[1], __O_DIRECTORY) != -1)
	{
		ft_printf("erreur : probleme fichier (dossier)\n");
		exit(1);
	}
	if (open(av[4], __O_DIRECTORY) != -1)
	{
		ft_printf("erreur : probleme fichier (dossier)\n");
		exit(1);
	}
}

void	lensto(t_stru *stru)
{
	int	i;

	i = -1;
	stru->lensto = 0;
	while (stru->sto[++i])
		stru->lensto++;
}

void	o(int r)
{
	if (r == 0)
	{
		ft_printf("error PATH\n");
		exit(1);
	}
}
