/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhpar <chanhpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 20:46:07 by chanhpar          #+#    #+#             */
/*   Updated: 2021/10/24 21:05:14 by chanhpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include "struct.h"

char	*read_dict(char *dictname)
{
	int		fd;
	int		size;
	char	*buff;

	size = 1024;
	buff = (char *)malloc(sizeof(char) * (size + 1));
	if (buff == NULL)
		return (NULL);
	fd = open(dictname, O_RDONLY);
	if (fd > 0)
	{
		read(fd, buff, size);
		close(fd);
	}
	return (buff);
}
