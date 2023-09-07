/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felsanch <felsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:29:24 by felsanch          #+#    #+#             */
/*   Updated: 2023/09/07 22:57:45 by felsanch         ###   ########.fr       */
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

// char	*ft_static_update(char *buffer)
// {
// 	char	*endline;
// 	char	*endbuffer;
// 	char	*new_buffer;

// 	endline = ft_strchr(buffer, '\n');
// 	if (endline == NULL)
// 		endline = buffer;
// 	endbuffer = ft_strchr(buffer, '\0');
// 	new_buffer = malloc (sizeof(char) * (endbuffer - endline + 1));
// 	if (!new_buffer)
// 		return (NULL);
// 	new_buffer = ft_substr(buffer, new_buffer);
// }

char	*ft_static_update(char *buffer)
{
	char	*new_buffer;
	int		bff_counter;
	int		new_bff_counter;
	int		tam;

	bff_counter = 0;
	new_bff_counter = 0;
	tam = ft_strlen(buffer);
	new_buffer = malloc(sizeof(char) * (tam - bff_counter + 1));
	if (!new_buffer)
		return (NULL);
	while (buffer[bff_counter] != '\n')
		bff_counter++;
	bff_counter++;
	while (bff_counter < tam)
	{
		new_buffer[new_bff_counter] = buffer[bff_counter];
		bff_counter++;
		new_bff_counter++;
	}
	return (new_buffer);
}

// char	*ft_static_update(char *buffer)
// {
// 	char	*new_buffer;
// 	int		bff_counter;
// 	int		new_bff_counter;
// 	int		tam;

// 	bff_counter = 0;
// 	new_bff_counter = 0;
// 	tam = ft_strlen(buffer);
// 	new_buffer = malloc(sizeof(char) * (tam - bff_counter + 1));
// 	if (!new_buffer)
// 		return (NULL);
// 	while (buffer[bff_counter] != '\n')
// 		bff_counter++;
// 	bff_counter++;
// 	while (bff_counter < tam)
// 	{
// 		new_buffer[new_bff_counter] = buffer[bff_counter];
// 		bff_counter++;
// 		new_bff_counter++;
// 	}
// 	return (new_buffer);
// }

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
	printf("El buffer, al principio es: %s\n", buffer);
	line = ft_get_line(buffer);
	buffer = ft_static_update(buffer);
	printf("El buffer, actualizado es: %s\n", buffer);
	return (line);
}

int	main(void)
{
	char		*line;
	ssize_t		fd;

	fd = open("fichero.txt", O_RDONLY);

	line = get_next_line(fd);
	free(line);
	printf ("La linea es: %s\n", line);
	close(fd);
	return (0);
}
