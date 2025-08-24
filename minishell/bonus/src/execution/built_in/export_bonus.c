/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:39:47 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/01 17:51:19 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built_in/builtin_bonus.h"

char	*join_and_expand_args(char **args, char **envp, int *last_exit_status)
{
	char	*joined_args;
	char	*expanded_arg;

	joined_args = join_args_with_space(args, 1);
	if (!joined_args)
	{
		ft_putstr_fd("export: memory allocation error\n", 2);
		return (NULL);
	}
	expanded_arg = expand_argument(joined_args, envp, last_exit_status, 0);
	free(joined_args);
	if (!expanded_arg)
	{
		ft_putstr_fd("export: memory allocation error\n", 2);
		return (NULL);
	}
	return (expanded_arg);
}

int	validate_export_arg(char *expanded_arg)
{
	if (!is_valid_identifier(expanded_arg))
	{
		ft_putstr_fd("export: ", 2);
		ft_putstr_fd(": not a valid identifier\n", 2);
		free(expanded_arg);
		return (0);
	}
	return (1);
}

char	*prepare_export_arg(char **args, char **envp, int *last_exit_status)
{
	char	*expanded_arg;

	expanded_arg = join_and_expand_args(args, envp, last_exit_status);
	if (!expanded_arg)
		return (NULL);
	if (!validate_export_arg(expanded_arg))
		return (NULL);
	return (expanded_arg);
}

int	is_valid_var_name(char *name)
{
	int	i;

	i = 0;
	if (!name || name[0] == '\0')
		return (0);
	if (!ft_isalpha(name[0]) && name[0] != '_')
		return (0);
	while (name[i])
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	builtin_export(char *cmd, char ***envp, int last_exit_status)
{
	char	**new_envp;
	int		ret_val;
	char	**args;

	args = ft_split_args(cmd, ' ');
	if (!args || !envp || !*envp)
		return (1);
	if (!args[1])
		return (print_sorted_env(*envp), 0);
	handle_args(args, envp);
	new_envp = process_export_args(args, *envp, &last_exit_status);
	if (!new_envp)
		return (1);
	ret_val = 0;
	if (new_envp != *envp)
	{
		free_char_array(*envp);
		*envp = new_envp;
	}
	else
		ret_val = 1;
	free_char_array(args);
	return (ret_val);
}
