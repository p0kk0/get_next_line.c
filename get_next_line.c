/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felsanch <felsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:29:24 by felsanch          #+#    #+#             */
/*   Updated: 2023/09/06 20:36:36 by felsanch         ###   ########.fr       */
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

char	*ft_newjoin(char *buffer, char *temp_buffer)
{
	char	*retornado;

	retornado = ft_join(buffer, temp_buffer);
	free(buffer);
	return (retornado);
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
		buffer = ft_newjoin(buffer, temp_buffer);
		free(temp_buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (buffer);
}

char	*ft_get_line(char *buffer)
{
	char	*line;
	char	*aux;
	int		counter;

	counter = 0;
	aux = ft_strchr(buffer, '\n');
	if (aux == NULL)
		aux = buffer - 1;
	line = malloc(sizeof(char) * (aux - buffer + 2)); //PROTEGER
	while (buffer[counter] != '\n' && buffer[counter])
	{
		line[counter] = buffer[counter];
		counter++;
	}
	if (aux != buffer - 1)
	{
		line[counter] = '\n';
		counter += 1;
	}
	line[counter] = '\0';
	return (line);
}

char	*ft_static_update(char *buffer)
{
	char	*new_buffer;
	int		bff_counter;
	int		new_bff_counter;
	int		tam;

	bff_counter = 0;
	new_bff_counter = 0;
	tam = ft_strlen(buffer);
	while (buffer[bff_counter] != '\n' && buffer[bff_counter])
		bff_counter++;
	bff_counter++;
	new_buffer = malloc(sizeof(char) * (tam - bff_counter + 1));
	if (!new_buffer)
		return (NULL);
	while (bff_counter < tam)
	{
		new_buffer[new_bff_counter] = buffer[bff_counter];
		bff_counter++;
		new_bff_counter++;
	}
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
	line = ft_get_line(buffer);
	buffer = ft_static_update(buffer);
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
		printf ("La linea es: %s", line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
