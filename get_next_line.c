/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felsanch <felsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:29:24 by felsanch          #+#    #+#             */
/*   Updated: 2023/09/10 17:35:30 by felsanch         ###   ########.fr       */
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
		{
			break ;
		}
	}
	return (buffer);
}

char	*ft_get_line(char *buffer)
{
	char	*line;
	char	*endline;
	int		counter;

	counter = 0;
	endline = ft_strchr(buffer, '\n');
	if (!endline)
		endline = ft_strchr(buffer, '\0');
	if (*endline == '\0')
		line = malloc(sizeof(char) * (endline - buffer + 1));
	else if (*endline == '\n')
		line = malloc(sizeof(char) * (endline - buffer + 2));
	if (!line)
		return (NULL);
	while (buffer[counter] != '\n' && buffer[counter])
	{
		line[counter] = buffer[counter];
		counter++;
	}
	if (*endline == '\n')
	{
		line[counter] = '\n';
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
	if (!ft_strchr(buffer, '\n'))
		return (free(new_buffer), free(buffer), NULL);
	else
	{
		new_buffer = ft_buffer_update(endline + 1, new_buffer);
		free(buffer);
	}
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (BUFFER_SIZE < 0 || fd < 0)
		return (0);
	if (!buffer)
		buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!ft_strchr(buffer, '\n'))
		buffer = ft_reading(buffer, fd);
	line = ft_get_line(buffer);
	if (!line)
		return (free(buffer), buffer = NULL, NULL);
	buffer = ft_static_update(buffer);
	return (line);
}

int	main(void)
{
	char		*line;
	ssize_t		fd;

	fd = open("fichero.txt", O_RDONLY);
	line = get_next_line(fd);
	//while (line)
	//{
		printf ("LA LINEA ES:%s", line);
		free(line);
		line = get_next_line(fd);
		printf ("LA LINEA ES:%s", line);
		free(line);
		line = get_next_line(fd);
		printf ("LA LINEA ES:%s", line);
		free(line);
		line = get_next_line(fd);
		printf ("LA LINEA ES:%s", line);
		free(line);
		line = get_next_line(fd);
		printf ("LA LINEA ES:%s", line);
		free(line);
		line = get_next_line(fd);
		printf ("LA LINEA ES:%s", line);
		free(line);
		line = get_next_line(fd);
		printf ("LA LINEA ES:%s", line);
		free(line);
		line = get_next_line(fd);
		printf ("LA LINEA ES:%s", line);
		free(line);
		line = get_next_line(fd);printf ("LA LINEA ES:%s", line);
		free(line);
		line = get_next_line(fd);printf ("LA LINEA ES:%s", line);
		free(line);
		line = get_next_line(fd);printf ("LA LINEA ES:%s", line);
		free(line);
		line = get_next_line(fd);
	//}
	close(fd);
	return (0);
}
