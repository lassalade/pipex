/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelissal <eelissal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:42:25 by eelissal          #+#    #+#             */
/*   Updated: 2025/03/06 15:13:24 by eelissal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h> // read
# include <stdlib.h> // malloc & free

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 120
# endif

int		strlen_gnl(char *s);
char	*ft_strjoin_gnl(char *line, char *buffer);
char	*ft_strchr_gnl(char *s, int c);
void	*ft_memset_gnl(void *s, int c, size_t n);
char	*ft_strdup_gnl(char *s);

char	*get_next_line(int fd);

#endif