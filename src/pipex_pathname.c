/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pathname.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelissal <eelissal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:03:47 by eelissal          #+#    #+#             */
/*   Updated: 2025/03/23 20:23:05 by eelissal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_cmd_name(char *cmd, char *cmd_name)
{
	int	len;
	int	i;

	if (!cmd)
		return (NULL);
	len = 0;
	while (cmd[len] == ' ')
	{
		if (!cmd[len + 1])
			return (NULL);
		len++;
	}
	while (cmd[len] && cmd[len] != ' ')
		len++;
	cmd_name = malloc(len + 1);
	if (!cmd_name)
		return (NULL);
	i = 0;
	while (i < len)
	{
		cmd_name[i] = cmd[i];
		i++;
	}
	cmd_name[len] = '\0';
	return (cmd_name);
}

char	**get_path(char **envp, char *cmd_name)
{
	int		i;
	char	*path;
	char	**paths;

	path = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = envp[i] + 5;
			break ;
		}
		i++;
	}
	if (!path)
	{
		free(cmd_name);
		return (NULL);
	}
	paths = ft_split(path, ':');
	return (paths);
}

char	*get_full_path(char *dir, char *cmd_name)
{
	char	*full_path;
	char	*tmp1;
	char	*tmp2;

	tmp1 = ft_strcdup(dir, ' ');
	if (!tmp1)
		return (NULL);
	tmp2 = ft_strjoin(tmp1, "/");
	free(tmp1);
	if (!tmp2)
		return (NULL);
	full_path = ft_strjoin(tmp2, cmd_name);
	free(tmp2);
	if (!full_path)
		return (NULL);
	return (full_path);
}

char	*find_cmd_path(char *cmd_name, char **paths)
{
	char	*cmd_path;
	int		i;

	i = 0;
	cmd_path = NULL;
	while (paths[i])
	{
		cmd_path = get_full_path(paths[i], cmd_name);
		if (!cmd_path)
		{
			free(cmd_name);
			return (NULL);
		}
		if (cmd_path && access(cmd_path, X_OK) == 0)
		{
			free(cmd_name);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	free(cmd_name);
	return (NULL);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char	*cmd_name;
	char	**paths;
	char	*cmd_path;

	if (cmd && access(cmd, X_OK) == 0)
		cmd_path = cmd;
	else
	{
		cmd_name = NULL;
		cmd_name = get_cmd_name(cmd, cmd_name);
		if (!cmd_name)
			return (NULL);
		paths = get_path(envp, cmd_name);
		if (!paths)
			return (NULL);
		cmd_path = find_cmd_path(cmd_name, paths);
		free_args(paths);
		if (!cmd_path)
			return (NULL);
	}
	if (cmd_path)
		return (cmd_path);
	free_args(paths);
	return (NULL);
}
