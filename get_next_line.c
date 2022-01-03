/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:09:30 by aalvarez          #+#    #+#             */
/*   Updated: 2021/07/29 13:01:34 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_bufffree(char *buffer)
{
	free (buffer);
	return (NULL);
}

char	*ft_linefree(char *line)
{
	free (line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	int			bytes;
	char		*buffer;
	static char	*full;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(full, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes] = '\0';
		if (bytes < 0)
			return (ft_bufffree (buffer));
		full = ft_strjoin(full, buffer);
	}
	free(buffer);
	line = ft_linejoin(full);
	full = ft_substr(full, ft_slen(full, '\n') + 1, ft_slen(full, 0));
	if (!bytes && *line == '\0')
		return (ft_linefree(line));
	return (line);
}
