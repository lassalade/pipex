/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelissal <eelissal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:00:39 by eelissal          #+#    #+#             */
/*   Updated: 2025/03/07 13:21:00 by eelissal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**parse_cmd(char *cmd)
{
	int		count;
	int		i;
	char	**args;

	count = 1;
	i = 0;
	while (cmd[i])
	{
		if (cmd[i++] == ' ')
			count++;
	}
	args = malloc((count + 1) * sizeof(char *));
	if (!args)
		exit(127);
	args = fill_args(cmd, args);
	if (!args)
		return (NULL);
	return (args);
}

void	execute_cmd(char *cmd, char **envp)
{
	char	*cmd_path;
	char	**args;

	args = parse_cmd(cmd);
	if (!args)
		exit(127);
	cmd_path = get_cmd_path(args[0], envp);
	if (!cmd_path)
	{
		free_args(args);
		perror("Command not found");
		exit(127);
	}
	execve(cmd_path, args, envp);
	perror("execve failed");
	free(cmd_path);
	free_args(args);
	exit(127);
}

void	first_process(int fd[2], char **argv, char **envp)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
	{
		perror("Infile error");
		dup2(infile, 0);
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		exit(1);
	}
	dup2(infile, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	close(fd[1]);
	close(infile);
	execute_cmd(argv[2], envp);
	exit(127);
}

void	second_process(int fd[2], char **argv, char **envp)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
	{
		perror("Outfile error");
		dup2(fd[0], 0);
		dup2(outfile, 1);
		close(fd[0]);
		close(fd[1]);
		exit(1);
	}
	dup2(fd[0], 0);
	dup2(outfile, 1);
	close(fd[0]);
	close(fd[1]);
	close(outfile);
	execute_cmd(argv[3], envp);
	exit(127);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	id1;
	int	id2;

	if (argc != 5)
		return (1);
	if (pipe(fd) == -1)
		exit(1);
	id1 = fork();
	if (id1 == -1)
		exit(1);
	if (id1 == 0)
		first_process(fd, argv, envp);
	id2 = fork();
	if (id2 == -1)
		exit(1);
	if (id2 == 0)
		second_process(fd, argv, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid_status(id1, id2);
	return (0);
}
