/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:57:58 by bsafi             #+#    #+#             */
/*   Updated: 2023/04/13 18:41:15 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexa_up(unsigned int n)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789ABCDEF";
	if (n >= 16)
	{
		i = ft_printhexa_up(n / 16);
		ft_putchar(base[n % 16]);
	}
	else
		ft_putchar(base[(n % 16)]);
	return (i + 1);
}
