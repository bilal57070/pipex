
#ifndef pipex_h
# define pipex_h

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include "libft/inc/get_next_line.h"
# include "libft/inc/ft_printf.h"
# include "libft/inc/libft.h"

typedef struct s_stru
{
    char    **sto;
	int		lensto;
    int     in;
    int     out;
	char	**flags;
	int		*sizef;
	char	**cmd;
	int		*sizecmd;
	char	**paths;
	char	**all;
	char	**all2;
	char	**tabarg;
	char	**tabarg2;
}           t_stru;

void    countin(t_stru *stru, char **av);
void    takeav(char **av, t_stru *stru);
void    printab(t_stru *stru);
void	firstway(t_stru *stru, pid_t pid, char **av, char **env);
void	getflags(t_stru *stru);
void	sizeflags(t_stru *stru);
void	printsize(t_stru *stru);
void	sizecmd(t_stru *stru);
void	getcmd(t_stru *stru);
void	lensto(t_stru *stru);
void	lenarg(t_stru *stru, char **av);
void	fils(t_stru *stru, int *pipefd, char **av);
void	tabarg(t_stru *stru);
void	pere(t_stru *stru, int *pipefd, char **av);
void	makefils(t_stru *stru, char **av);
void	prin(t_stru *stru);
void	first(t_stru *stru, char **av);
void	taball(t_stru *stru);
void	second(t_stru *stru, int *pipefd2, char **av);
void	taball2(t_stru *stru);

#endif