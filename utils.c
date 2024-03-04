/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:00:52 by mirio             #+#    #+#             */
/*   Updated: 2024/03/04 16:13:19 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tab(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	getpath(t_stru *stru, char **env)
{
	int		i;
	int		j;
	int		r;
	char	*line;

	i = -1;
	r = 0;
	while (env[++i])
	{
		j = 4;
		if (ft_strncmp(env[i], "PATH", j++) == 0)
		{
			r = 1;
			line = ft_strdup(env[i] + j);
		}
	}
	o(r);
	stru->path = ft_split(line, ':');
	free(line);
	i = -1;
	while (stru->path[++i])
		stru->path[i] = ft_strjoin2(stru->path[i], "/");
}

char	*pathcmd(t_stru *stru, char *cmd)
{
	int		i;
	char	*test;

	i = -1;
	while (stru->path[++i])
	{
		test = ft_strjoin(stru->path[i], cmd);
		if (access(test, F_OK | X_OK) == 0)
			return (test);
		free(test);
	}
	printf("probleme accès ou exec cmd \n");
	return (0);
	//exit(1);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = -1;
	j = 0;
	str = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	if (!s1 || !s2)
		return (0);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	if (s1)
		free(s1);
	str[i] = '\0';
	return (str);
}

char	*ft_strdup2(char *s)
{
	char	*s2;
	int		i;

	if (!s)
		return (NULL);
	s2 = malloc(sizeof(char) * (ft_strlen(s) + 1));
	i = 0;
	if (!s2)
		return (0);
	while (s[i])
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
