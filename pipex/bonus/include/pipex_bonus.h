/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:45:40 by mtahalla          #+#    #+#             */
/*   Updated: 2025/03/05 17:31:15 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "utils/utils_bonus.h"

typedef struct s_data{
	int		i;
	int		fd[2];
	int		pid;
	int		infile;
	int		outfile;
	int		prev_fd;
}	t_data;
typedef struct s_child_args
{
	char	*cmd;
	char	**env;
	int		fd_in;
	int		fd_out;
	int		fd_to_close;
}	t_child_args;
typedef struct s_args
{
	int		argc;
	char	**argv;
	char	**env;
}	t_args;
char	*ft_get_path(char *cmd, char **env, int i);
void	free_split(char **split);
char	*execute_script(char *cmd);
void	child_process(t_child_args *args);
void	process_iofile(t_data *data, t_args *args);
void	handle_error(const char *msg, int fd1, int fd2);

#endif