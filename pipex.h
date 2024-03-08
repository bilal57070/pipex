/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 23:32:47 by bsafi             #+#    #+#             */
/*   Updated: 2024/03/04 17:43:27 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <sys/wait.h>
# include "libft/inc/get_next_line.h"
# include "libft/inc/ft_printf.h"
# include "libft/inc/libft.h"

typedef struct s_stru
{
	char	**sto;
	int		lensto;
	int		in;
	int		out;
	char	**flags;
	int		*sizef;
	char	**cmd;
	int		*sizecmd;
	char	*tmp;
	char	**paths;
	char	**all;
	char	**all2;
	char	**tabarg;
	char	**tabarg2;
	char	**path;
	int		fd;
}			t_stru;

void	countin(t_stru *stru, char **av);
void	takeav(char **av, t_stru *stru);
void	printab(t_stru *stru);
void	firstway(t_stru *stru, pid_t pid, char **av, char **env);
void	getflags(t_stru *stru);
void	sizeflags(t_stru *stru);
void	printsize(t_stru *stru);
void	sizecmd(t_stru *stru);
void	getcmd(t_stru *stru);
void	lensto(t_stru *stru);
void	lenarg(t_stru *stru, char **av);
void	fils(t_stru *stru, int *pipefd);
void	tabarg(t_stru *stru);
void	pere(t_stru *stru, int *pipefd);
void	makefils(t_stru *stru);
void	prin(t_stru *stru);
void	first(t_stru *stru, char **av, char **env);
void	taball(t_stru *stru);
void	second(t_stru *stru, int *pipefd2, char **av, char **env);
void	taball2(t_stru *stru);
void	testcmd(t_stru *stru);
void	free_tab(char **str);
void	getpaths(t_stru *stru);
void	getpath(t_stru *stru, char **env);
char	*pathcmd(t_stru *stru, char *cmd);
void	testfile(char **av, t_stru *stru);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_strdup2(char *s);
void	f(char *test, int *pipefd2, char **env, t_stru *stru);
void	p(int fd, int *pipefd2, char **env, t_stru *stru);
void	h(t_stru *stru, int i);
void	o(int r);

#endif