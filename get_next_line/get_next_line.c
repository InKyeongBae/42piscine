/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:10:26 by ibae              #+#    #+#             */
/*   Updated: 2022/03/19 12:10:28 by ibae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *backup)
{
	int		i;
	char	*s;

	i = 0;
	if (!backup[i])
		return (NULL);
	while (backup[i] != '\0' && backup[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (backup[i] != '\0' && backup[i] != '\n')
	{
		s[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
	{
		s[i] = backup[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_backup(char *backup)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (backup[i] != '\0' && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (backup[i])
		s[c++] = backup[i++];
	s[c] = '\0';
	free(backup);
	return (s);
}

char	*ft_read_and_backup(int fd, char *backup)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(backup, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		backup = ft_strjoin(backup, buff);
	}
	free(buff);
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	backup = ft_read_and_backup(fd, backup);
	if (!backup)
		return (NULL);
	line = ft_get_line(backup);
	backup = ft_backup(backup);
	return (line);
}
