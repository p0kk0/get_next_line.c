/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felsanch <felsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:29:24 by felsanch          #+#    #+#             */
/*   Updated: 2023/09/05 19:54:34 by felsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *buffer, char start)
{
	int		i;
	char	*new_buffer;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] != start)
		i++;
	i++;
	while (buffer[i] < BUFFER_SIZE)
	{
		new_buffer[i] = buffer[i];
		i++;
	}
	return (new_buffer);
}

static char	*ft_strchr(char *buffer, char a)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == a)
		{
			buffer[i] = '\n';
			return (&buffer[i]);
		}
		i++;
	}
	return (NULL);
}

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
		if (ft_strchr(buffer, '\n'))
			break ;
		free(temp_buffer);
	}
	return (buffer);
}

char	*ft_get_line(char *buffer)
{
	char	*line;
	int		counter;

	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	counter = 0;
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
	int		counter;
	char	*new_buffer;

	counter = 0;
	while (buffer[counter] != '\n')
	{
		counter++;
	}
	counter++;
	while (buffer[counter])
	{
		counter++;
	}
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (BUFFER_SIZE < 0 || fd < 0)
		return (0);
	buffer = ft_reading(buffer, fd);
	line = ft_get_line(buffer);
	//printf("El buffer es: %s\n", buffer);
	//printf("La linea es: %s\n", line);
	buffer = ft_static_update(buffer);
	return (line);
}

int	main(void)
{
	int			counter;
	char		*line;
	ssize_t		fd;

	counter = 2;
	fd = open("fichero.txt", O_RDONLY);
	while (counter > 0)
	{
	line = get_next_line(fd);
	printf ("The line is: %s\n", line);
	counter--;
	}
	close(fd);
	return (0);
}
