/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:13:30 by bsafi             #+#    #+#             */
/*   Updated: 2023/06/05 17:05:57 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readline(int fd, char *tmp)
{
	char	*buf;
	int		j;

	if (!tmp)
		tmp = ft_strdup("");
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	j = 1;
	while (!ft_strchr(tmp, '\n') && j > 0)
	{
		j = read(fd, buf, BUFFER_SIZE);
		if (j == -1)
		{
			free(buf);
			free(tmp);
			return (0);
		}
		buf[j] = 0;
		tmp = ft_free(tmp, buf);
	}
	free (buf);
	return (tmp);
}

char	*bef(char *tmp)
{
	int		i;
	char	*final;

	i = 0;
	if (!tmp)
		return (0);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	final = malloc(sizeof(char) * (i + 2));
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		final[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
	{
		final[i] = tmp[i];
		i++;
	}
	final[i] = '\0';
	return (final);
}

char	*fin(char *tmp)
{
	int		i;
	int		j;
	char	*poub;

	i = 0;
	j = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (!tmp[i])
	{
		free(tmp);
		return (0);
	}
	poub = malloc(sizeof(char) * (ft_strlen(tmp) - i + 1));
	if (!poub)
		return (0);
	i++;
	while (tmp[i])
		poub[j++] = tmp[i++];
	poub[j] = '\0';
	free(tmp);
	return (poub);
}

char	*get_next_line(int fd)
{
	static char	*tmp[FOPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	tmp[fd] = readline(fd, tmp[fd]);
	if (!tmp[fd])
		return (NULL);
	line = bef(tmp[fd]);
	tmp[fd] = fin(tmp[fd]);
	if (line[0] == '\0')
	{
		free(tmp[fd]);
		free(line);
		return (NULL);
	}
	return (line);
}
/*
int	main()
{
	int		fd;
	char	*buf;
	int	i = -1;

	fd = open ("rev.c", O_RDONLY);
	while (++i != 5)
		printf("%s\n",get_next_line(fd));
	
}*/
