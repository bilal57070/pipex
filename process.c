/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:30:31 by mirio             #+#    #+#             */
/*   Updated: 2024/03/02 15:04:49 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*void	makefils(t_stru *stru)
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
		exit(1);
	else if (pid == 0)
	{	
		fils(stru, pipefd);
	}
	else if (pid > 0)
	{
		waitpid(pid, NULL, 0);
		pere(stru, pipefd);
		//printf("test\n");
	}
	//}
}*/

// avec dup2 change la sortie d'execve en 
//mettant la sortie pipe pour ecrire dedans
/*void	fils(t_stru *stru, int *pipefd)
{
	char	**env;
	//int		i;
	//char	buf;
	//int		f;
	//pid_t	pid;

	env = NULL;
	//i = 0;
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
	while (i < 3)
	{
		printf("commande : %s\n", stru->cmd[i]);
		i++;
	}
	dup2(pipefd[1], STDOUT_FILENO);
	execve("/usr/bin/which", stru->tabarg, env);
	free_tab(stru->tabarg);
	free_tab(stru->cmd);
	if (execve("/usr/bin/which", stru->tabarg, env) == -1)
	{
		ft_printf("erreur cmd\n");
		exit(1);
	}*/
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
	}
	//}
}*/

/*void	tabarg(t_stru *stru)
{
	int	i;
	int	j;

	i = 0;
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
}*/

/*void	pere(t_stru *stru, int *pipefd)
{
	char	buf;
	int		i;
	//int		j;

	close(pipefd[1]);
	//exit(1);
	//stru->paths = malloc(sizeof(char *) * (stru->lensto));
	i = 0;
	//j = 0;
	//stru->paths[i] = malloc(sizeof(char) * (stru->sizecmd[i] + 10));
	if (read(pipefd[0], &buf, 1) == -1) //ca marche 
	pas mais faut que t'arrive si pas bonne cmd
	{
		ft_printf("erreur cmd\n");
		exit(1);
	}
	stru->tmp = malloc(sizeof(char) * (stru->sizecmd[i] 
	+ stru->sizecmd[i + 1] + 20));
	while (read(pipefd[0], &buf, 1) > 0)
	{
		stru->tmp[i] = buf;
		i++;
		if (buf == '\n')
		{
			if (read(pipefd[0], &buf, 1) == 0)
			{
				printf("cbien ?????\n");
				//stru->paths[i][j] = '\0';
				break;
			}
			else
			{
				j = 0;
				i++;
				stru->paths[i] = malloc(sizeof(char) * 
				(stru->sizecmd[i] + 10));
				stru->paths[i][j++] = buf;
				continue;
			}
			//i++;
			printf("ENFIN RENTRER\n");
			//stru->paths[i] = malloc(sizeof(char) * (stru->sizecmd[i] + 10));
			//j = 0;

			continue;
		}
		//stru->paths[i][j] = buf;
		//printf("on voit: %c\n", stru->paths[i][j]);
		//j++;
		if (stru->paths[i][j - 1] == '\n')
		{
			printf("ENFIN RENTRER\n");
			//stru->paths[i][j + 1] = '\0'; //jsp si jdevrais faire ca
			i++;
			stru->paths[i] = malloc(sizeof(char) * 
			(stru->sizecmd[i] + 10));
			j = 0;
		}
	}
	stru->tmp[i] = '\0';
	close(pipefd[0]);
	//first(stru, av);
	getpaths(stru);
	i = 0;
	while(stru->paths[i++])
		printf("paths : %s\n", stru->paths[i]);
}*/

/*void	getpaths(t_stru *stru)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = -1;
	j = 0;
	stru->paths = malloc(sizeof(char *) * (stru->lensto - 1));
	printf("lensto %d\n", stru->lensto);
	stru->paths[i] = malloc(sizeof(char) * (stru->sizecmd[i] + 10));
	while (stru->tmp[++k])
	{
		if (stru->tmp[k] == '\n')
		{
			if (stru->tmp[k + 1] == '\0')
			{
				//printf("alors\n");
				//break;
			}
			//printf("alors\n");
			i++;
			stru->paths[i] = malloc(sizeof(char) * 
			(stru->sizecmd[i] + 10));
			k++;
			j = 0;
		}
		stru->paths[i][j] = stru->tmp[k];
		j++;
	}
	stru->paths[i] = 0;
	//prin(stru);
	//testcmd(stru);
	//first(stru, av);
}*/

void	testcmd(t_stru *stru)
{
	int	i;

	i = 0;
	while (stru->paths[i])
	{
		i++;
		ft_printf("i : %d\n", i);
	}
	if (i != (stru->lensto - 2))
	{
		ft_printf("erreur cmd\n");
		exit(1);
	}
}

/*void	prin(t_stru *stru)
{
	int	i;

	i = 0;
	while(stru->paths[i])
	{
		printf("paths : %s\n", stru->paths[i]);
		i++;
		printf("i : %d\n", i);
	}
}*/
//execve("usr/bin/which", stru->flags[i], env);

// engro pour exec une cmd ce sera  execve(stru->paths[i], all, env)
//sachant que all sera un tab de tab contenant stru->cmd, stru->flags et NULL.

void	first(t_stru *stru, char **av, char **env)
{
	int		i;
	int		pipefd2[2];
	pid_t	pid;
	char	*test;

	i = 0;
	if (pipe(pipefd2) == -1)
		exit(1);
	test = NULL;
	test = pathcmd(stru, stru->cmd[i]);
	pid = fork();
	if (pid == -1)
		exit(1);
	else if (pid == 0)
	{
		stru->fd = open(av[1], O_RDONLY);
		f(test, pipefd2, env, stru);
	}
	else if (pid > 0)
	{
		free(test);
		waitpid(pid, NULL, 0);
		second(stru, pipefd2, av, env);
	}
}

void	f(char *test, int *pipefd2, char **env, t_stru *stru)
{
	char	**test2;
	int		i;

	i = 0;
	close(pipefd2[0]);
	test2 = malloc(sizeof(char *) * 3);
	dup2(stru->fd, STDIN_FILENO);
	dup2(pipefd2[1], STDOUT_FILENO);
	test2[i] = ft_strdup2(stru->cmd[i]);
	test2[i + 1] = ft_strdup2(stru->flags[i]);
	test2[i + 2] = NULL;
	if (execve(test, test2, env) != 0)
	{
		ft_printf("error\n");
		exit(1);
	}
	free_tab(test2);
	free(test);
	free_tab(stru->flags);
	free_tab(stru->cmd);
	free(stru->sizecmd);
}

/*void	taball(t_stru *stru)
{
	int	i;
	int	j;

	i = 0;
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
}*/

void	second(t_stru *stru, int *pipefd2, char **av, char **env)
{
	int		fd;
	pid_t	pid;

	close(pipefd2[1]);
	pid = fork();
	if (pid == -1)
		exit(1);
	else if (pid == 0)
	{
		fd = open(av[4], O_WRONLY);
		p(fd, pipefd2, env, stru);
	}
	else if (pid > 0)
	{
		free_tab(stru->sto);
		free_tab(stru->path);
		free_tab(stru->flags);
		free_tab(stru->cmd);
		free(stru->sizecmd);
		free(stru->sizef);
		waitpid(pid, NULL, 0);
		close(pipefd2[0]);
	}
}

void	p(int fd, int *pipefd2, char **env, t_stru *stru)
{
	char	**test2;
	char	*test;
	int		i;

	i = 1;
	test = NULL;
	test = pathcmd(stru, stru->cmd[i]);
	test2 = malloc(sizeof(char *) * 3);
	dup2(fd, STDOUT_FILENO);
	dup2(pipefd2[0], STDIN_FILENO);
	test2[0] = ft_strdup2(stru->cmd[i]);
	test2[i] = ft_strdup2(stru->flags[i]);
	test2[i + 1] = NULL;
	execve(test, test2, env);
	close(pipefd2[0]);
	free_tab(test2);
	free_tab(stru->cmd);
	free_tab(stru->flags);
	free(stru->sizecmd);
}
