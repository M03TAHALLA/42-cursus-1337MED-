/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:46:37 by mtahalla          #+#    #+#             */
/*   Updated: 2025/03/04 21:59:44 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex_bonus.h"

void	open_infile(t_data *data, t_args *args)
{
	data->infile = open(args->argv[1], O_RDONLY);
	if (data->infile < 0)
		handle_error("pipex ", data->fd[0], data->fd[1]);
	data->prev_fd = data->infile;
}

static	void	check_arg(char c, t_data *data)
{
	if (c == '\0')
	{
		write(2, "pipex : permission denied\n", 28);
		close(data->fd[0]);
		close(data->fd[1]);
		close(3);
		close(4);
		if (data->i == 0)
			close(data->infile);
		exit(EXIT_FAILURE);
	}
}

void	open_outfile(t_data *data, t_args *args)
{
	data->outfile = open(args->argv[args->argc - 1], 
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->outfile < 0)
		handle_error("pipex ", data->fd[0], data->fd[1]);
}

void	setup_child_args(t_child_args *child_args, t_data *data, t_args *args)
{
	if (data->i == args->argc - 4)
		open_outfile(data, args);
	check_arg(args->argv[data->i + 2][0], data);
	if (data->i == args->argc - 4)
	{
		child_args->cmd = args->argv[data->i + 2];
		child_args->env = args->env;
		child_args->fd_in = data->prev_fd;
		child_args->fd_out = data->outfile;
		child_args->fd_to_close = data->fd[1];
		child_process(child_args);
		close(data->outfile);
	}
	else 
	{
		child_args->cmd = args->argv[data->i + 2];
		child_args->env = args->env;
		child_args->fd_in = data->prev_fd;
		child_args->fd_out = data->fd[1];
		child_args->fd_to_close = data->fd[0];
		child_process(child_args);
		close(data->fd[1]);
	}
}

void	process_iofile(t_data *data, t_args *args)
{
	t_child_args	child_args;

	if (data->pid == 0) 
	{
		if (data->i == 0)
			open_infile(data, args);
		setup_child_args(&child_args, data, args);
		close(data->prev_fd);
	}
}
