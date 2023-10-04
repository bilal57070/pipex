/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:19:32 by bsafi             #+#    #+#             */
/*   Updated: 2023/04/13 18:16:18 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_putstr(char *s);
char	*ft_strchr(const char *s, int c);
int		ft_putnbr(int n);
int		ft_printf(const char *s, ...);
int		ft_putunbr(unsigned int n);
int		ft_printhexa_up(unsigned int n);
int		ft_printhexa_low(unsigned int n);
int		ft_putptr(unsigned long int n);

#endif
