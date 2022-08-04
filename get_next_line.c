/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhapa <chanhapa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:27:09 by chanhapa          #+#    #+#             */
/*   Updated: 2022/08/04 16:53:15 by chanhapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*_read(char *backup, int fd)
{
	char	*buffer;
	int		read_size;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_size = 1;
	while (!ft_strchr(backup, '\n') && read_size != 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_size] = 0;
		backup = ft_strjoin(backup, buffer);
	}
	return (backup);
}

char	*_get_line(char *backup)
{
	int		i;
	char	*line;

	i = 0;
	if (!backup[0])
		return (NULL);
	while (backup && backup[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = -1;
	while (backup[++i] != '\n')
		line[i] = backup[i];
	return (line);
}

char	*_next(char *backup)
{
	int		i;
	int		j;
	char	*next_backup;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	next_backup = (char *)malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
	if (!next_backup)
		return (NULL);
	i++;
	j = 0;
	while (backup[i])
		next_backup[j++] = backup[i++];
	free(backup);
	return (next_backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	backup = _read(backup, fd);
	if (!backup)
		return (NULL);
	line = _get_line(backup);
	backup = _next(backup);
	return (line);
}
