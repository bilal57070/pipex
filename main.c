/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:32:14 by mirio             #+#    #+#             */
/*   Updated: 2024/03/04 20:52:51 by bsafi            ###   ########.fr       */
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
	testfile(av, &stru);
	takeav(av, &stru);
	sizeflags(&stru);
	first(&stru, av, env);
	free(stru.flags[1]);
	free(stru.flags[2]);
	free(stru.flags[0]);
	free(stru.flags);
}
