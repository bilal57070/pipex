/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:32:14 by mirio             #+#    #+#             */
/*   Updated: 2024/02/26 00:10:42 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_stru	stru;

	getpath(&stru, env);
	testfile(av);
	takeav(av, &stru);
	sizeflags(&stru);
	first(&stru, av, env);
}
