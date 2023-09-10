/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felsanch <felsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:27:07 by felsanch          #+#    #+#             */
/*   Updated: 2023/09/10 18:06:01 by felsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join(char *buffer, char *temp_bff)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(buffer) + ft_strlen(temp_bff) + 1));
	if (!str)
		return (NULL);
	//if (buffer)
	//{
		while (buffer[i])
		{
			str[i] = buffer[i];
			i++;
		}
		free(buffer);
	//}
	while (temp_bff[j])
	{
		str[i + j] = temp_bff[j];
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

char	*ft_buffer_update(char *buffer, char *new_buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		new_buffer[i] = buffer[i];
		i++;
	}
	new_buffer[i] = '\0';
	return (new_buffer);
}
