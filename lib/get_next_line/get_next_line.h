/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/09 23:16:26 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/21 14:34:15 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
int		ft_strlen_n(char *str);
void	clean_buffer(char *buffer, int bytes_read, int full);
void	move_buffer(char *buffer, int bytes_read);
char	*ft_realloc(char *str, char *buffer, int bytes_read);

#endif
