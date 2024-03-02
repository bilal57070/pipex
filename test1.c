/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:53:01 by mirio             #+#    #+#             */
/*   Updated: 2024/03/02 15:39:51 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	sizeflags(t_stru *stru)
{
	int	i;
	int	j;

	i = 0;
	lensto(stru);
	stru->sizef = malloc(sizeof(int) * (stru->lensto + 9));
	while (stru->sto[i + 1] && i < (stru->lensto - 2))
	{
		stru->sizef[i] = 0;
		j = 0;
		while (stru->sto[i + 1][j])
		{
			j++;
			if (stru->sto[i + 1][j] == ' ')
			{
				while (stru->sto[i + 1][++j])
				{
					stru->sizef[i]++;
				}
			}
		}
		i++;
	}
	sizecmd(stru);
}

void	getflags(t_stru *stru)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	stru->flags = malloc(sizeof(char *) * (stru->lensto - 1));
	if (!stru->flags)
		exit(1);
	while (stru->sto[i + 1] && i < (stru->lensto - 2))
	{
		stru->flags[i] = malloc(sizeof(char) * (stru->sizef[i] + 1));
		j = -1;
		k = 0;
		while (stru->sto[i + 1][++j])
		{
			if (stru->sto[i + 1][j] == ' ')
			{
				while (stru->sto[i + 1][++j])
					stru->flags[i][k++] = stru->sto[i + 1][j];
				break ;
			}
		}
		stru->flags[i][k] = '\0';
		i++;
	}
	stru->flags[i] = 0;
	h(stru);
	/*i = -1;
	while (stru->flags[++i])
	{
		if (stru->sizef[i] == 0)
		{
			free(stru->flags[i]);
			stru->flags[i] = NULL;
		}
	}*/
}

void	h(t_stru *stru)
{
	int	i;

	i = -1;
	while (stru->flags[++i])
	{
		if (stru->sizef[i] == 0)
		{
			free(stru->flags[i]);
			stru->flags[i] = NULL;
		}
	}
}

/*void	printsize(t_stru *stru)
{
	int	i;

	i = 0;
	while (stru->sto[i])
	{
		printf("sizef = %d\n", stru->sizef[i]);
		i++;
	}
}*/

void	sizecmd(t_stru *stru)
{
	int	i;
	int	j;

	i = 0;
	stru->sizecmd = malloc(sizeof(int) * (stru->lensto - 1));
	while (stru->sto[i + 1] && i < (stru->lensto - 2))
	{
		stru->sizecmd[i] = 0;
		j = -1;
		while (stru->sto[i + 1][++j])
		{
			if (stru->sto[i + 1][j] == ' ')
			{
				break ;
			}
			stru->sizecmd[i]++;
		}
		i++;
	}
	getcmd(stru);
}

void	getcmd(t_stru *stru)
{
	int	i;
	int	j;

	i = 0;
	stru->cmd = malloc(sizeof(char *) * (stru->lensto - 1));
	while (stru->sto[i + 1] && i < (stru->lensto - 2))
	{
		stru->cmd[i] = malloc(sizeof(char) * (stru->sizecmd[i] + 1));
		j = -1;
		while (stru->sto[i + 1][++j] != ' ' && stru->sto[i + 1][j] != '\0')
			stru->cmd[i][j] = stru->sto[i + 1][j];
		stru->cmd[i][j] = '\0';
		i++;
	}
	stru->cmd[i] = 0;
	getflags(stru);
}
