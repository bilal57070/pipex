/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirio <mirio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:53:01 by mirio             #+#    #+#             */
/*   Updated: 2024/01/09 00:58:21 by mirio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// belek fait une fonction openfork pour qu'une fonction ouvre automatiquement un pipe 
//et un processus fils ptete fait une aussi pour close
void	firstway(t_stru *stru, pid_t pid, char **av, char **env)
{
	//int		pipefd[2];
	//char	*buf;
	int	fd;

	/*if (pipe(pipefd) == -1)
	{
		ft_printf("pipe cassé\n");
		exit(EXIT_FAILURE);
	}*/
	fd = open("a.c", O_WRONLY);
	if (pid == -1)
		ft_printf("fork cassé\n");
	else if(pid == 0)
	{
		dup2(fd, STDOUT_FILENO);
		//close(pipefd[1]);
		execve("/usr/bin/which", av + 1, env);
	}
	else
		ft_printf("tets\n");
}


void	lensto(t_stru *stru)
{
	int	i;

	i = -1;
	stru->lensto = 0;
	while (stru->sto[++i])
		stru->lensto++;
}

void	sizeflags(t_stru *stru)
{
	int	i;
	int	j;

	i = 0;
	lensto(stru);
	stru->sizef = malloc(sizeof(int) * (stru->lensto + 9));
	while(stru->sto[++i] && i < (stru->lensto - 1))
	{
		j = 0;
		while (stru->sto[i][j])
		{
			j++;
			if (stru->sto[i][j] == ' ')
			{
				//stru->sizef[i] = 0;
				while (stru->sto[i][++j])
				{
					stru->sizef[i]++;
				}
			}
		}
	}
	//printsize(stru);
	sizecmd(stru);
}

void	getflags(t_stru *stru)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	stru->flags = malloc(sizeof(char *) * (stru->lensto));
	while(stru->sto[++i] && i < (stru->lensto - 1))
	{
		stru->flags[i] = malloc(sizeof(char) * (stru->sizef[i] + 1));
		j = -1;
		k = 0;
		while (stru->sto[i][++j])
		{
			if (stru->sto[i][j] == ' ')
			{
				while (stru->sto[i][++j])
					stru->flags[i][k++] = stru->sto[i][j];
			}
		}
		stru->flags[i][k] = '\0';
	}
	stru->flags[i] = 0;
	i = -1;
	while (stru->sto[++i])
		printf("flags = %s\n", stru->flags[i]);
}
void	printsize(t_stru *stru)
{
	int	i;

	i = 0;
	while (stru->sto[i])
	{
		printf("sizef = %d\n", stru->sizef[i]);
		i++;
	}
}

void	sizecmd(t_stru *stru)
{
	int	i;
	int	j;

	i = 0;
	stru->sizecmd = malloc(sizeof(int) * (stru->lensto));
	while(stru->sto[++i] && i < (stru->lensto - 1))
	{
		j = -1;
		while (stru->sto[i][++j])
		{
			if (stru->sto[i][j] == ' ')
			{
				break;
			}
			stru->sizecmd[i]++;
		}
	}
	i = -1;
	//while (stru->sto[++i])
	//	printf("sizecmd = %d\n", stru->sizecmd[i]);
	getcmd(stru);
}

void	getcmd(t_stru *stru)
{
	int	i;
	int	j;

	i = 0;
	stru->cmd = malloc(sizeof(char *) * (stru->lensto));
	while(stru->sto[i + 1] && i < (stru->lensto - 1))
	{
		printf("test %d\n", i);
		stru->cmd[i] = malloc(sizeof(char) * (stru->sizecmd[i] + 1));
		j = -1;
		while (stru->sto[i][++j] != ' ' && stru->sto[i][j] != '\0')
			stru->cmd[i][j] = stru->sto[i][j];
		stru->cmd[i][j] = '\0';
		i++;
	}
	stru->cmd[i] = 0;
	//i = -1;
	//while (stru->sto[++i])
	//	printf("cmd = %s\n", stru->cmd[i]);
	getflags(stru);
}

// l'ordre serait : fork , execve la cmd1 sur file1, pipe la sortie de cmd1 sur cmd2
// , tout sort sur le file2.

/*int	getflags(t_stru *stru, char **av)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	sizeflags(stru, av);
	//stru->flag1 = malloc(sizeof(char) * stru->sizef1);
	//stru->flag2 = malloc(sizeof(char) * stru->sizef2);
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if ((av[i][j] == ' ') && (i == 1 || i == 2))
			{
				k = 0;
				while (av[i][++j] && i == 1 stru->sizef1 != 0)
					stru->flag1 = ft_strdup(av[i]);
				j--;
				while (av[i][++j] && i == 2)
					stru->flag2 = ft_strdup(av[i]);
			}
		}
	}
	ft_printf("flag1 : %s\n", stru->flag1);
	ft_printf("flag2 : %s\n", stru->flag2);
	return (0);
}

void	sizeflags(t_stru *stru, char **av)
{
	int	i;
	int	j;

	i = 0;
	stru->sizef1 = 0;
	stru->sizef2 = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if ((av[i][j] == ' ') && (i == 1 || i == 2))
			{
				j++;
				if (i == 1)
					stru->sizef1 = (ft_strlen(av[i]) - j);
				if (i == 2)
					stru->sizef2 = (ft_strlen(av[i]) - j);
				ft_printf("sizef1 : %d\n", stru->sizef1);
				ft_printf("sizef2 : %d\n", stru->sizef2);
			}
		}
	}
}

void	getcmd(t_stru *stru, char **av)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	stru->cmd1 = malloc(sizeof(char) * stru->sizecmd1);
	stru->cmd2 = malloc(sizeof(char) * stru->sizecmd2);
	while (av[++i])
	{
		j = -1;
		k = 0;
		while (av[i][++j] != ' ' && i == 1)
			stru->cmd1[k++] = av[i][j];
		while (av[i][++j] != ' ' && i == 2)
			stru->cmd2[k++] = av[i][j];
	}
}

void	sizecmd(t_stru *stru, char **av)
{
	int	i;
	int	j;

	i = 0;
	stru->sizecmd1 = 0;
	stru->sizecmd2 = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j] != ' ' && i == 1)
			stru->sizecmd1++;
		while (av[i][++j] != ' ' && i == 2)
			stru->sizecmd2++;
	}
}
*/
/* refaire les meme focntions pour avoir les commandes isolés dans une str ( getcmd et sizecmd)*/
