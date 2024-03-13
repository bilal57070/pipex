/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:41:50 by bsafi             #+#    #+#             */
/*   Updated: 2024/02/04 18:44:52 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s2;
	int		i;

	write(1, "hello\n", 6);
	s2 = malloc(sizeof(char) * (ft_strlen(s) + 1));
	i = 0;
	if (!s2)
	{
		return (0);
	}
	while (s[i])
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
