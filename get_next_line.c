/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:33:02 by danimart          #+#    #+#             */
/*   Updated: 2024/01/22 16:14:13 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_fd(char **files, int fd)
{
	if (files[fd] != NULL)
	{
		free(files[fd]);
		files[fd] = NULL;
	}
	return (NULL);
}

static char	*get_line(char **files, int fd)
{
	char	*buff;
	char	*res;
	int		i;

	if (!files[fd])
		return (NULL);
	buff = files[fd];
	i = gnl_strchr(files[fd], '\n');
	if (i == -1)
	{
		if (gnl_strlen(files[fd]) <= 0)
			return (free_fd(files, fd));
		res = gnl_strdup(files[fd]);
		free_fd(files, fd);
		return (res);
	}
	res = gnl_substr(buff, 0, i + 1);
	files[fd] = gnl_substr(buff, i + 1, (gnl_strlen(buff) - i));
	free(buff);
	return (res);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*files[FD_SIZE];
	int			read_res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (files[fd] == NULL)
		files[fd] = gnl_strdup("");
	read_res = 1;
	while (read_res > 0)
	{
		if (gnl_strchr(files[fd], '\n') == -1)
		{
			read_res = read(fd, buf, BUFFER_SIZE);
			if (read_res == -1)
				return (free_fd(files, fd));
			buf[read_res] = '\0';
			files[fd] = gnl_strjoin(files[fd], buf);
		}
		else
			return (get_line(files, fd));
	}
	return (get_line(files, fd));
}
