/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:40:04 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/15 10:30:05 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

static void	handle_infile(char *filename, int fd1, int fd2)
{
	int	infile;

	infile = open(filename, O_RDONLY);
	if (infile < 0)
	{
		perror(filename);
		close(fd1);
		close(fd2);
		exit(EXIT_FAILURE);
	}
	dup2(infile, STDIN_FILENO);
	close(infile);
}

static void	handle_fd(int fd[2])
{
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
}

static void	execute_command(char *cmd, char **env)
{
	char	**args;
	char	*path;

	printf("%s\n",cmd);
	args = ft_split_args(cmd, ' ');
	printf("%s\n",args[0]);
	printf("%s\n",args[1]);
	if (!args)
		exit(EXIT_FAILURE);
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

void	execute_child_process1(char **argv, char **env, int fd[2])
{
	handle_infile(argv[1], fd[0], fd[1]);
	handle_fd(fd);
	if (argv[2][0] == '\0')
	{
		write(2, "pipex : permission denied\n", 28);
		close(0);
		close(1);
		exit(1);
	}
	execute_command(argv[2], env);
	close(fd[0]);
	close(fd[1]);
}

int	child_process1(char **argv, char **env, int fd[2])
{
	int	pid1;

	pid1 = fork();
	if (pid1 < 0)
	{
		perror("fork");
		close(fd[0]);
		close(fd[1]);
		exit(EXIT_FAILURE);
	}
	if (pid1 == 0)
	{
		execute_child_process1(argv, env, fd);
	}
	return (pid1);
}
