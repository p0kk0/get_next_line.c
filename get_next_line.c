/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felsanch <felsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:29:24 by felsanch          #+#    #+#             */
/*   Updated: 2023/08/31 20:24:17 by felsanch         ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char *s2)
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

char	*ft_strchr(const char *str, int c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *) &str[i]);
		i++;
	}
	return (NULL);
}

char	*get_line(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == '\0')
		{
			printf("Procesamos la línea.");
			return (str);
		}
		i++;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*temp_buffer;
	char		*line;
	ssize_t		read_bytes;

	read_bytes = 1;
	if (BUFFER_SIZE < 0 || fd < 0)
		return (0);
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	while (read_bytes > 0 )//&& ft_strchr(temp_buffer, '\n'))
	{
		temp_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!temp_buffer)
			return (NULL);
		read_bytes = read(fd, temp_buffer, BUFFER_SIZE);
		buffer = ft_strjoin(buffer, temp_buffer);
		get_line(buffer);
		free(temp_buffer);
		printf("|	|	|El temp_buffer contiene: %s\n", temp_buffer);
		printf("El buffer contiene: %s\n", buffer);
	}
	return (0);
}

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("fichero.txt", O_RDONLY);
	line = get_next_line(fd);
	//printf("The line is:%s\n", line);
	close(fd);
	return (0);
}
