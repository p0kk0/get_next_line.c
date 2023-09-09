/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felsanch <felsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:29:24 by felsanch          #+#    #+#             */
/*   Updated: 2023/09/08 17:15:22 by felsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_reading(char *buffer, int fd)
{
	char	*temp_buffer;
	ssize_t	read_bytes;

	read_bytes = 1;
	while (read_bytes > 0)
	{
		temp_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!temp_buffer)
			return (NULL);
		read_bytes = read(fd, temp_buffer, BUFFER_SIZE);
		buffer = ft_join(buffer, temp_buffer);
		free(temp_buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (buffer);
}

char	*ft_get_line(char *buffer)
{
	int		counter;
	char	*line;
	char	*endline;

	counter = 0;
	endline = ft_strchr(buffer, '\n');
	if (!endline)
		line = malloc(sizeof(char) * (endline - buffer + 1));
	else
		line = malloc(sizeof(char) * (endline - buffer + 2));
	if (!line)
		return (NULL);
	while (buffer[counter] != '\n')
	{
		line[counter] = buffer[counter];
		counter++;
	}
	line[counter] = '\0';
	return (line);
}

char	*ft_static_update(char *buffer)
{
	char	*endline;
	char	*endbuffer;
	char	*new_buffer;

	endline = ft_strchr(buffer, '\n');
	if (!endline)
		endline = buffer;
	endbuffer = ft_strchr(buffer, '\0');
	new_buffer = malloc (sizeof(char) * (endbuffer - endline + 1));
	if (!new_buffer)
		return (NULL);
	new_buffer = ft_buffer_update(buffer, new_buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (!buffer)
		buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (BUFFER_SIZE < 0 || fd < 0)
		return (0);
	buffer = ft_reading(buffer, fd);
	printf("EL BUFFER, AL PRINCIPIO ES:%s\n", buffer);
	line = ft_get_line(buffer);
	buffer = ft_static_update(buffer);
	printf("EL BUFFER ACTUALIZADO ES:%s\n", buffer);
	return (line);
}

int	main(void)
{
	char		*line;
	ssize_t		fd;

	fd = open("fichero.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line[0])
	{
		printf ("LA LINEA ES:%s\n", line);
		free(line);
		get_next_line(fd);
	}
	close(fd);
	return (0);
}
