/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felsanch <felsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:27:07 by felsanch          #+#    #+#             */
/*   Updated: 2023/09/07 22:56:44 by felsanch         ###   ########.fr       */
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

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*a;

// 	if (!s)
// 		return (NULL);
// 	if (ft_strlen(s) <= start)
// 		return (ft_strdup(""));
// 	if (ft_strlen(s) - start < len)
// 		len = ft_strlen(s) - start;
// 	a = malloc(len + 1);
// 	if (!a)
// 		return (NULL);
// 	ft_memcpy(a, s + start, len);
// 	a[len] = '\0';
// 	return (a);
// }
