

#include "pipex.h"

int main(int ac, char **av, char **env)
{
	pid_t	pid;
    t_stru stru;

    takeav(av, &stru);
	sizeflags(&stru);
	makefils(&stru,	av);
	//getflags(&stru, av);
	//pid = fork();
	//firstway(&stru, pid, av, env);
	//if (pid == 0)
	//{
	//}
}