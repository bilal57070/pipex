/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:16:51 by bsafi             #+#    #+#             */
/*   Updated: 2023/04/04 15:31:24 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	n;
	char	*str;

	if (!s1)
		return (0);
	if (!set)
		return ((char *)s1);
	n = ft_strlen(s1);
	i = 0;
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	if (i == ft_strlen(s1))
	{
		str = ft_strdup("");
		return (str);
	}
	while (ft_strchr(set, s1[n - 1]) && n > i)
		n--;
	str = ft_substr(s1, i, n - i);
	return (str);
}
/*int	main()
{
	char	*str = "    hello   ";
	char	*set = " ";
	printf("%s", ft_strtrim(str, set));
	
}*/
