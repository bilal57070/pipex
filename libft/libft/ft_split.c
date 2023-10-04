/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:23:06 by bsafi             #+#    #+#             */
/*   Updated: 2023/04/07 15:59:11 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	size_t	i;
	size_t	w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			w++;
			while (s[i] != c && s[i])
				i++;
			continue ;
		}
		i++;
	}
	return (w);
}

int	word_len(const char *s, char c, int start)
{
	int	i;
	int	count;

	i = start;
	count = 0;
	while (s[i] && s[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

char	*getword(const char *s, char c, int start)
{
	int		i;
	int		j;
	int		len;
	char	*word;

	i = start;
	j = 0;
	len = word_len(s, c, start);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (0);
	while (s[i] && s[i] != c)
	{
		word[j++] = s[i++];
	}
	word[j] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**r;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	r = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!r)
		return (0);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			r[j++] = getword(s, c, i);
			i++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	r[j] = 0;
	return (r);
}
