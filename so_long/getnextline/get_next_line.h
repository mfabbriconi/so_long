/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:03:43 by mfabbric          #+#    #+#             */
/*   Updated: 2023/01/30 15:16:43 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_strjoin(char *s1, char *s2);
char	*get_line(int fd, char *line);
char	*ft_strchr(char *s, int c);
char	*get_new_line(char *line);
char	*get_next_line(int fd);
char	*new_line(char *line);
int		ft_strlen(char *s);

#endif
