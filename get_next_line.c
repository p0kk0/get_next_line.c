/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felsanch <felsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:29:24 by felsanch          #+#    #+#             */
/*   Updated: 2023/09/04 17:47:59 by felsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_join(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

static char	*ft_strchr(char *buffer, char a)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == a)
		{
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
		printf("%s\n", buffer);
		free(temp_buffer);
	}
	//printf("%s\n", buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	//char		*line;

	buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (BUFFER_SIZE < 0 || fd < 0)
		return (0);
	buffer = ft_reading(buffer, fd);
	//line = ft_get_line(buffer);
	//buffer = ft_static_update(buffer);
	//return (line);
	return (buffer);
}

int	main(void)
{
	char		*line;
	ssize_t		fd;

	fd = open("fichero.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("The line is:%s\n", line);
	close(fd);
	return (0);
}
