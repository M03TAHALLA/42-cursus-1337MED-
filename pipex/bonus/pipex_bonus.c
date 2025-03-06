/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:41:08 by mtahalla          #+#    #+#             */
/*   Updated: 2025/03/05 17:31:27 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex_bonus.h"

void	handle_error(const char *msg, int fd1, int fd2)
{
	perror(msg);
	close(fd1);
	close(fd2);
	exit(EXIT_FAILURE);
}

static void	execute_command(char *cmd, char **env)
{
	char	**args;
	char	*path;

	args = ft_split_args(cmd, ' ');
	if (!args)
		exit(EXIT_FAILURE);
	path = ft_get_path(args[0], env, 0);
	if (!path)
	{
		write(2, "pipex: command not found: ", 26);
		write(2, args[0], ft_strlen(args[0]));
		write(2, "\n", 1);
		free_split(args);
		close(0);
		close(1);
		exit(127);
	}
	if (execve(path, args, env) == -1)
	{
		perror("pipex:");
		free_split(args);
		close(0);
		close(1);
		exit(EXIT_FAILURE);
	}
}

void	child_process(t_child_args *args)
{
	if (args->fd_in != STDIN_FILENO)
	{
		dup2(args->fd_in, STDIN_FILENO);
		close(args->fd_in);
	}
	if (args->fd_out != STDOUT_FILENO)
	{
		dup2(args->fd_out, STDOUT_FILENO);
		close(args->fd_out);
	}
	close(args->fd_to_close);
	execute_command(args->cmd, args->env);
}

void	proccess(t_data *data, t_args *args)
{
	data->prev_fd = -1;
	while (data->i < args->argc - 3)
	{
		if (data->i < args->argc - 4)
		{
			if (pipe(data->fd) == -1)
				handle_error("pipe", data->fd[0], data->fd[1]);
		}
		data->pid = fork();
		if (data->pid < 0)
			handle_error("fork", data->fd[0], data->fd[1]);
		process_iofile(data, args);
		if (data->prev_fd != -1)
			close(data->prev_fd);
		if (data->i < args->argc - 4)
			close(data->fd[1]);
		data->prev_fd = data->fd[0];
		data->i++;
	}
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	t_args	args;
	int		i;
	int		status;

	args.argc = argc;
	args.argv = argv;
	args.env = env;
	if (argc < 5)
		handle_error("Usage: ./pipex infile cmd1 cmd2 ... cmd outfile", 3, 4);
	data.i = 0;
	data.outfile = -1;
	proccess(&data, &args);
	i = 0;
	waitpid(data.pid, &status, 0);
	while (i < argc - 2)
	{
		wait(NULL);
		i++;
	}
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}
