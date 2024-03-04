/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:30:31 by mirio             #+#    #+#             */
/*   Updated: 2024/03/04 16:19:15 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	pid = fork();
	if (pid == -1)
		exit(1);
	else if (pid == 0)
	{
		test = pathcmd(stru, stru->cmd[i]);
		stru->fd = open(av[1], O_RDONLY);
		if (test)
			f(test, pipefd2, env, stru);
	}
	else if (pid > 0)
	{
		//free(test);
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
	if (test)
	{
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
}
