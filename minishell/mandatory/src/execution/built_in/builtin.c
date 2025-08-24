/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:10:52 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/02 20:44:53 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

bool	is_builtin(char *cmd)
{
	if (!cmd)
		return (false);
	return (!ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, "cd")
		|| !ft_strcmp(cmd, "pwd") || !ft_strcmp(cmd, "export")
		|| !ft_strcmp(cmd, "unset") || !ft_strcmp(cmd, "env")
		|| !ft_strcmp(cmd, "exit"));
}

int	execute_builtin(t_ast_node *node, char ***envp, 
		int last_exit_status, bool has_pipe)
{
	if (!ft_strcmp(node->args[0], "echo"))
		return (builtin_echo(node->args, &last_exit_status, envp));
	if (!ft_strcmp(node->args[0], "cd"))
		return (builtin_cd(node->args, *envp, last_exit_status));
	if (!ft_strcmp(node->args[0], "pwd"))
		return (builtin_pwd());
	if (!ft_strcmp(node->args[0], "export"))
		return (builtin_export(node->cmd, envp, last_exit_status));
	if (!ft_strcmp(node->args[0], "unset"))
		return (builtin_unset(node->args, envp));
	if (!ft_strcmp(node->args[0], "env"))
		return (builtin_env(*envp));
	if (!ft_strcmp(node->args[0], "exit"))
		return (builtin_exit(node->args, last_exit_status, has_pipe));
	return (1);
}
