/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:32:14 by mirio             #+#    #+#             */
/*   Updated: 2024/03/04 15:40:08 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_stru	stru;

	if (ac != 5)
	{
		ft_printf("erreur arg\n");
		exit(1);
	}
	getpath(&stru, env);
	testfile(&stru, av, env);
	takeav(av, &stru);
	sizeflags(&stru);
	first(&stru, av, env);
}

void	newfile(t_stru *stru, char **av, char **env)
{
	pid_t	pid;
	char	*test;
	char	**test2;
	int		i;

	i = 0;
	pid = fork();
	if (pid == -1)
		exit(1);
	else if (pid == 0)
	{
		test2 = malloc(sizeof(char *) * 3);
		test = pathcmd(stru, "touch");
		test2[i] = ft_strdup2("touch");
		test2[i + 1] = ft_strdup2(av[4]);
		test2[i + 2] = NULL;
		execve(test, test2, env);
		free_tab(test2);
		free(test);
	}
	else
		waitpid(pid, NULL, 0);
}
