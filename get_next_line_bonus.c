/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 08:59:41 by ecousill          #+#    #+#             */
/*   Updated: 2024/10/09 11:29:30 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*remainder[MAX_FD];
	int			bytes_read;
	char		*line;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!has_newline(remainder[fd]) && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			if (remainder[fd])
			{
				line = remainder[fd];
				remainder[fd] = update_remainder(remainder[fd]); // Necesaria?? o ponemos return (remainder[fd])
				return (line);
			}
			free(remainder[fd]);
			remainder[fd] = NULL;
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		remainder[fd] = join_strings(remainder[fd], buffer);
		if (!remainder[fd])
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	line = extract_line(remainder[fd]);
	remainder[fd] = update_remainder(remainder[fd]);
	return (line);
}
