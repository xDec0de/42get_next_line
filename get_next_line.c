/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:33:02 by danimart          #+#    #+#             */
/*   Updated: 2021/11/08 13:00:57 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char **files)
{
	if (*files)
	{
		free(*files);
		*files = NULL;
	}
	return (NULL);
}

static char	*get_line(char **files, int fd)
{
	char	*tmp;
	char	*res;
	int		i;

	if (!files[fd])
		return (NULL);
	tmp = files[fd];
	i = ft_strchr(tmp, '\n');
	if (i == -1)
	{
		if (ft_strlen(tmp) <= 0)
			return (ft_free(files + fd));
		res = ft_strdup(tmp);
		ft_free(&files[fd]);
		return (res);
	}
	res = ft_substr(tmp, 0, i + 1);
	files[fd] = ft_substr(tmp, i + 1, (ft_strlen(tmp) - i));
	ft_free(&tmp);
	return (res);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*files[FD_SIZE];
	int			read_res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!files[fd])
		files[fd] = ft_strdup("");
	read_res = 1;
	while (read_res > 0)
	{
		if (ft_strchr(files[fd], '\n') == -1)
		{
			read_res = read(fd, buf, BUFFER_SIZE);
			if (read_res == -1)
				return (ft_free(files + fd));
			buf[read_res] = '\0';
			files[fd] = ft_strjoin(files[fd], buf);
		}
		else
			return (get_line(files, fd));
	}
	return (get_line(files, fd));
}
