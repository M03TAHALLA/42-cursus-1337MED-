/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:39:56 by mtahalla          #+#    #+#             */
/*   Updated: 2025/03/05 16:58:59 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

static	void	handle_outfile(char *filename, int fd1, int fd2)
{
	int	outfile;

	outfile = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
	{
		perror(filename);
		close(fd1);
		close(fd2);
		exit(EXIT_FAILURE);
	}
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
}

static void	handle_fd2(int fd[2])
{
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
}

static void	execute_command2(char *cmd, char **env)
{
	char	**args;
	char	*path;

	args = ft_split_args(cmd, ' ');
	path = ft_get_path(args[0], env, 0);
	if (!path)
	{
		write(2, "pipex: command not found: \n", 27);
		write(2, args[0], ft_strlen(args[0]));
		write(2, "\n", 1);
		free_split(args);
		close(0);
		close(1);
		exit(127);
	}
	else if (execve(path, args, env) == -1)
	{
		perror("pipex");
		free_split(args);
		close(0);
		close(1);
		exit(EXIT_FAILURE);
	}
}

void	execute_child_process2(char **argv, char **env, int fd[2])
{
	handle_outfile(argv[4], fd[0], fd[1]);
	handle_fd2(fd);
	if (argv[3][0] == '\0')
	{
		write(2, "pipex : permission denied\n", 28);
		close(0);
		close(1);
		exit(1);
	}
	if (ft_strcmp(argv[3], "") == 0)
		execute_command2(argv[2], env);
	else
		execute_command2(argv[3], env);
	close(fd[0]);
	close(fd[1]);
}

int	child_process2(char **argv, char **env, int fd[2])
{
	int	pid2;

	pid2 = fork();
	if (pid2 < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid2 == 0)
	{
		execute_child_process2(argv, env, fd);
	}
	return (pid2);
}
