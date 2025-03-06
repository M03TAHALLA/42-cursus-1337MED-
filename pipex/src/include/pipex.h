/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:33:56 by mtahalla          #+#    #+#             */
/*   Updated: 2025/03/05 17:08:53 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "utils/utils.h"

typedef struct s_data{
	int	fd[2];
	int	pid2;
	int	status;
}t_data;
char	*ft_get_path(char *cmd, char **env, int i);
int		child_process1(char **argv, char **env, int fd[2]);
int		child_process2(char **argv, char **env, int fd[2]);
void	free_split(char **split);
char	*execute_script(char *cmd);
void	handle_error(const char *msg);

#endif