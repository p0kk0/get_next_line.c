/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felsanch <felsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:29:24 by felsanch          #+#    #+#             */
/*   Updated: 2023/08/30 19:28:09 by felsanch         ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*temp_buffer;
	ssize_t		read_bytes;

	buffer = NULL;
	read_bytes = 1; //Decimos que es 1, para que entre dentro del bucle.
	if (BUFFER_SIZE < 0 || fd < 0)
		return (0);
	while (read_bytes > 0) //Cuando los bytes leídos sean 0, habremos acabado.
	{
		temp_buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!temp_buffer)
			return (0);
		read_bytes = read(fd, temp_buffer, BUFFER_SIZE);
		buffer = ft_strjoin(buffer, temp_buffer);
		printf("Bytes read: %zd\n", read_bytes);
		printf("El buffer contiene: %s\n", buffer);
		printf("El temp_buffer contiene: %s\n", temp_buffer);
	}
	printf("El buffer contiene: %s\n", buffer);
	return (temp_buffer);
}

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("fichero.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("The line is:%s\n", line);
	return (0);
}
