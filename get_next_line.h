/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felsanch <felsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:12:03 by felsanch          #+#    #+#             */
/*   Updated: 2023/08/30 17:03:23 by felsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFER_SIZE
# define BUFFER_SIZE 3
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

//GET_NEXT_LINE: Return a line from a FD. If the function is called again, returns next line.
/**
 * @brief Get the next line object
 * 
 * @param fd File descriptor given to apply the function. 
 * @return char* a pointer to the buffer where the string (line) is alocated.
 */
char	*get_next_line(int fd);
char	*ft_strchr(char const *temp_buffer, int c);

#endif