/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:39:13 by mtahalla          #+#    #+#             */
/*   Updated: 2025/03/05 17:07:15 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

void	handle_error(const char *msg)
{
	perror(msg);
	close(0);
	close(1);
	exit(EXIT_FAILURE);
}

static void	check_arguments(int argc)
{
	if (argc != 5)
	{
		write(2, "error : ./pipex file1 cmd1 cmd2 file2\n", 38);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	int		i;

	i = 0;
	check_arguments(argc);
	if (pipe(data.fd) == -1)
		handle_error("pipe");
	child_process1(argv, env, data.fd);
	data.pid2 = child_process2(argv, env, data.fd);
	close(data.fd[0]);
	close(data.fd[1]);
	waitpid(data.pid2, &data.status, 0);
	while (i < argc - 2)
	{
		wait(NULL);
		i++;
	}
	if (WIFEXITED(data.status))
		return (WEXITSTATUS(data.status));
	return (1);
}
