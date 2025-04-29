/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelissal <eelissal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:00:42 by eelissal          #+#    #+#             */
/*   Updated: 2025/03/23 22:44:27 by eelissal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_args(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return ;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	count_len(char *cmd, char *end)
{
	int	len;

	len = 0;
	while (cmd[len] && (end == NULL || &cmd[len] != end))
		len++;
	return (len);
}

void	waitpid_status(int id1, int id2)
{
	int	status1;
	int	status2;

	waitpid(id1, &status1, 0);
	waitpid(id2, &status2, 0);
	if (WIFEXITED(status2))
		exit(WEXITSTATUS(status2));
	else if (WIFSIGNALED(status2))
		exit(WTERMSIG(status2));
	else if (WIFSTOPPED(status2))
		exit(WSTOPSIG(status2));
	else if (WIFEXITED(status1))
		exit(WEXITSTATUS(status1));
	else if (WIFSIGNALED(status1))
		exit(WTERMSIG(status1));
	else if (WIFSTOPPED(status1))
		exit(WSTOPSIG(status1));
	else
		exit(1);
}

char	**fill_args(char *cmd, char **args)
{
	int		i;
	char	*end;
	int		len;

	i = 0;
	while (*cmd)
	{
		while (*cmd == ' ')
			cmd++;
		if (!*cmd)
			break ;
		end = ft_strchr(cmd, ' ');
		len = count_len(cmd, end);
		args[i] = malloc(len + 1);
		if (!args[i])
		{
			free_args(args);
			return (NULL);
		}
		ft_memcpy(args[i], cmd, len);
		args[i++][len] = '\0';
		cmd += len;
	}
	args[i] = NULL;
	return (args);
}

void	failed_child_process(int fd[2], int id)
{
	if (id == -1)
	{
		close(fd[0]);
		close(fd[1]);
		exit(1);
	}
}
