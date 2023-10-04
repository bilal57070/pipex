/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:02:10 by bsafi             #+#    #+#             */
/*   Updated: 2023/04/07 14:57:27 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*sr;
	char	*ds;

	i = 0;
	sr = (char *)src;
	ds = (char *)dest;
	if (!dest && !src)
		return (0);
	if (ds > sr)
	{
		while (i < n)
		{
			ds[n - 1] = sr[n - 1];
			n--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
