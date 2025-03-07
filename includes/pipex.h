/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelissal <eelissal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:20:09 by eelissal          #+#    #+#             */
/*   Updated: 2025/03/07 13:31:30 by eelissal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "ft_printf_bonus.h"
# include "get_next_line.h"
# include <fcntl.h>     // open
# include <stdbool.h>   // bool
# include <stdlib.h>    // malloc
# include <unistd.h>    // fork
# include <sys/wait.h>  // wait, waitpid
# include <signal.h>    // waitpid status
# include <errno.h>

char	*ft_strcdup(const char *s, char n);
void	free_args(char **args);
int		count_len(char *cmd, char *end);
void	waitpid_status(int id1, int id2);
char	**fill_args(char *cmd, char **args);

char	*get_cmd_name(char *cmd, char *cmd_name);
char	**get_path(char **envp);
char	*get_full_path(char *dir, char *cmd_name);
char	*find_cmd_path(char *cmd_name, char **paths);
char	*get_cmd_path(char *cmd, char **envp);

#endif