/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:42:00 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/04 17:58:00 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	handle_expanded_cmd(char *expanded_cmd, char **env, int free_f)
{
	char	**args;
	int		i;

	i = 0;
	args = ft_split_args(expanded_cmd, ' ');
	while (args[i])
	{
		args[i] = expand_argument(args[i], env, 0, 0);
		if (!args || !args[i])
		{
			if (args)
				free_args(args);
			exit(0);
		}
		i++;
	}
	if (ft_strchr(args[0], '/'))
		execute_direct_path(args, env);
	else
		execute_from_path(args, env);
	if (free_f)
		free(expanded_cmd);
}

void	execute_command(char *cmd, char **env, int *last_exit_status)
{
	char	*expanded_cmd;
	int		finder;

	handle_empty_cmd(cmd);
	if (cmd[0] == '$' && ft_strlen(cmd) > 1)
	{
		expanded_cmd = expand_argument(cmd, env, last_exit_status, &finder);
		if (!expanded_cmd || ft_strlen(expanded_cmd) == 0)
		{
			if (expanded_cmd)
				free(expanded_cmd);
			return ;
		}
		free(expanded_cmd);
	}
	expanded_cmd = expand_argument(cmd, env, last_exit_status, &finder);
	if (!expanded_cmd)
		exit(EXIT_FAILURE);
	if (!ft_strchr(cmd, '$') || finder == 1 
		|| ft_strnstr(cmd, "awk", ft_strlen(cmd)))
		handle_expanded_cmd(cmd, env, 0);
	else
		handle_expanded_cmd(expanded_cmd, env, 1);
}
