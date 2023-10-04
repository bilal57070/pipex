/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:22:51 by bsafi             #+#    #+#             */
/*   Updated: 2023/04/13 18:18:31 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long n)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (n >= 16)
	{
		i = ft_putptr(n / 16);
		ft_putchar(base[n % 16]);
	}
	else
		ft_putchar(base[(n % 16)]);
	return (i + 1);
}
