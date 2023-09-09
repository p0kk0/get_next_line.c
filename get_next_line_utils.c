/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felsanch <felsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:27:07 by felsanch          #+#    #+#             */
/*   Updated: 2023/09/08 17:18:01 by felsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *buffer, char a)
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
	if (a == '\0')
		return (&buffer[i]);
	return (NULL);
}

char	*ft_buffer_update(char	*buffer, char *new_buffer)
{
	int		buff_counter;
	int		newbuff_counter;

	buff_counter = 0;
	newbuff_counter = 0;
	while (buffer[buff_counter] != '\n')
		buff_counter++;
	buff_counter++;
	while (buffer[buff_counter])
	{
		new_buffer[newbuff_counter] = buffer[buff_counter];
		buff_counter++;
		newbuff_counter++;
	}
	new_buffer[newbuff_counter] = '\0';
	return (new_buffer);
}
