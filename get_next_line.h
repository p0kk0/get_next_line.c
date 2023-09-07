/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felsanch <felsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:12:03 by felsanch          #+#    #+#             */
/*   Updated: 2023/09/07 22:54:56 by felsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFER_SIZE
# define BUFFER_SIZE 13
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char		*get_next_line(int fd);
char		*ft_join(char *s1, char *s2);
int			ft_strlen(char *str);
char		*ft_strchr(char *buffer, char a);
char		*ft_substr(char *s1, char *s2);
#endif
