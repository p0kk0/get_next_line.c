/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felsanch <felsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:12:03 by felsanch          #+#    #+#             */
/*   Updated: 2023/09/11 19:19:38 by felsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char		*get_next_line(int fd);
char		*ft_join(char *s1, char *s2);
int			ft_strlen(char *str);
char		*ft_strchr(char *buffer, char a);
void		ft_buffer_update(char *buffer, char *new_buffer);
void		*ft_calloc(size_t count, size_t size);
#endif
