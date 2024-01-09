/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirio <mirio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:30:31 by mirio             #+#    #+#             */
/*   Updated: 2024/01/05 18:13:58 by mirio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	makefils(t_stru *stru, char **av)
{
	pid_t	pid;
	int		pipefd[2];
	//int		i;

	//i = -1;
	if (pipe(pipefd) == -1)
	{
		printf("error pipe\n");
		exit(1);
	}
	//while (++i < 2)
	//{
	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
	{	
		fils(stru, pipefd, av);
	}
	else if (pid > 0)
	{
		waitpid(pid, NULL, 0);
		pere(stru, pipefd, av);
		//printf("test\n");
	}
	//}
}

// avec dup2 change la sortie d'execve en mettant la sortie pipe pour ecrire dedans
void	fils(t_stru *stru, int *pipefd, char **av)
{
	char	**env;
	int		i;
	//char	buf;
	int		fd;
	pid_t	pid;

	env = NULL;
	i = 0;
	//fd = open("a.c", O_WRONLY);
	//if (i == 0)
	//{
	//close(pipefd[0]);
	//printf("hello\n");
	//while (++i < (stru->lensto - 1))
	//{
	//	pid = fork();
	//	if (pid == -1)
	//		return (1);
	//	else if (pid == 0)
	//	{
	close(pipefd[0]);
	tabarg(stru);
	/*while (i < 3)
	{
		printf("commande : %s\n", stru->cmd[i]);
		i++;
	}*/
	dup2(pipefd[1], STDOUT_FILENO);
	execve("/usr/bin/which", stru->tabarg, env); //a la base jfaisais avec (av + 1)
	//	}
	//	else
	//		waitpid(pid, NULL, 0);
	//}
	//close(pipefd[1]);
	//i++;
	//}
	//else if (i == 1)
	//{
	/*close(pipefd[1]);
	while (read(pipefd[0], &buf, 1) > 0)
	{
		write(1, &buf, 1);
		write(1, "\n", 1);
	}*/
	//}
}

void	tabarg(t_stru *stru)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	stru->tabarg = malloc(sizeof(char *) * 3);
	stru->tabarg[j] = malloc(sizeof(char) * 15);
	stru->tabarg[j] = "/usr/bin/which";
	j++;
	stru->tabarg[j] = malloc(sizeof(char) * 6);
	stru->tabarg[j] = "pipex";
	j++;
	stru->tabarg[j] = ft_strdup(stru->cmd[i]);
	j++;
	i++;
	stru->tabarg[j] = ft_strdup(stru->cmd[i]);
}

void	pere(t_stru *stru, int *pipefd, char **av)
{
	char	buf;
	int		i;
	int		j;

	close(pipefd[1]);
	stru->paths = malloc(sizeof(char *) * (stru->lensto));
	i = 0;
	j = 0;
	stru->paths[i] = malloc(sizeof(char) * (stru->sizecmd[i] + 10));
	while (read(pipefd[0], &buf, 1) > 0)
	{
		if (buf == '\n')
		{
			i++;
			printf("ENFIN RENTRER\n");
			stru->paths[i] = malloc(sizeof(char) * (stru->sizecmd[i] + 10));
			j = 0;
			continue;
		}
		stru->paths[i][j] = buf;
		printf("on voit: %c\n", stru->paths[i][j]);
		j++;
		/*if (stru->paths[i][j - 1] == '\n')
		{
			printf("ENFIN RENTRER\n");
			//stru->paths[i][j + 1] = '\0'; //jsp si jdevrais faire ca
			i++;
			stru->paths[i] = malloc(sizeof(char) * (stru->sizecmd[i] + 10));
			j = 0;
		}*/
	}
	close(pipefd[0]);
	prin(stru);
	first(stru, av);
	/*i = 0;
	while(stru->paths[i++])
		printf("paths : %s\n", stru->paths[i]);*/
}

void	prin(t_stru *stru)
{
	int	i;

	i = -1;
	while(stru->paths[++i])
		printf("paths : %s\n", stru->paths[i]);
}
//execve("usr/bin/which", stru->flags[i], env);

// engro pour exec une cmd ce sera  execve(stru->paths[i], all, env)
//sachant que all sera un tab de tab contenant stru->cmd, stru->flags et NULL.

void	first(t_stru *stru, char **av)
{
	int		i;
	int		pipefd2[2];
	int		fd;
	char	**env;
	pid_t	pid;

	i = 0;
	char *argg[] = {"/usr/bin/ls", "-l", NULL};
	if (pipe(pipefd2) == -1)
	{
		printf("probleme pipe\n");
		return (1);
	}
	printf("le paths la c : %s\n", stru->paths[i]);
	pid = fork();
	env = NULL;
	if (pid == -1)
		return(1);
	else if (pid == 0)
	{
		printf("pk...\n");
		taball(stru);
		close(pipefd2[0]);
		fd = open(av[1], O_RDONLY);
		dup2(fd, STDIN_FILENO);
		//write(pipefd2[1], "oe", 2);
		dup2(pipefd2[1], STDOUT_FILENO);
		//execve("/usr/bin/ls", argg, NULL);
		//execve("/usr/bin/ls", stru->all, env);
		execve(stru->paths[i], stru->all, env);
	}
	else if (pid > 0)
	{
		waitpid(pid, NULL, 0);
		second(stru, pipefd2, av);
	}
}
// faut refaire belek processus fils dans first
// belek la sortie premiere cmd dans pipe et direct sur ce pipe j'exec 2e cmd et sortie 2e file

void	taball(t_stru *stru)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	stru->all = malloc(sizeof(char *) * 3);
	stru->all[j] = ft_strdup(stru->paths[i]);
	j++;
	//stru->all[j] = malloc(sizeof(char) * 6);
	//stru->all[j] = "pipex";
	//j++;
	//stru->all[j] = ft_strdup(stru->cmd[i]);
	//j++;
	stru->all[j] = ft_strdup(stru->flags[i]);
	//j++;
	//stru->all[j] = NULL;
}

void	second(t_stru *stru, int *pipefd2, char **av)
{
	int		i;
	int		fd;
	char	**env;
	char	buf;

	i = 1;
	env = NULL;
	printf("JE SUIS LA\n");
	fd = open(av[4], O_WRONLY);
	close(pipefd2[1]);
	//while (read(pipefd2[0], &buf, 1) > 0)
	//{
	//	write(1, &buf, 1);
	//}
	dup2(pipefd2[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	taball2(stru);
	//execve("/usr/bin/wc", stru->all2, env);
	execve(stru->paths[i], stru->all2, env);
}

void	taball2(t_stru *stru)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	stru->all2 = malloc(sizeof(char *) * 3);
	stru->all2[j] = ft_strdup(stru->paths[i]);
	j++;
	//stru->all2[j] = malloc(sizeof(char) * 6);
	//stru->all2[j] = "pipex";
	//j++;
	//stru->all2[j] = ft_strdup(stru->cmd[i]);
	//j++;
	stru->all2[j] = ft_strdup(stru->flags[i]);
}



/*PROBLEME:
lorsque dans FILS je veux exec which je peux pas lfaire avec av quand y'a des flags
donc faut le faire avec stru->cmd mais ca ne marche pas pour la premiere cmd ???
no comprendo */