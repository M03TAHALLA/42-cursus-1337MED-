/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 09:23:55 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/13 15:48:41 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin.h"

char	**ft_copy_env(char **envp)
{
	int		count;
	int		i;
	char	**new_envp;

	count = 0;
	while (envp[count])
		count++;
	new_envp = (char **)malloc(sizeof(char *) * (count + 1));
	if (!new_envp)
		return (NULL);
	i = -1;
	while (++i < count)
	{
		new_envp[i] = ft_strdup(envp[i]);
		if (!new_envp[i])
		{
			while (--i >= 0)
			{
				free(new_envp[i]);
				new_envp[i] = NULL;
			}
			return (free(new_envp), new_envp = NULL, NULL);
		}
	}
	return (new_envp[count] = NULL, new_envp);
}

void	free_char_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

static int	handle_invalid_var_name(char *var_name)
{
	if (!is_valid_var_name(var_name))
	{
		ft_putstr_fd("ShellNote export: `", 2);
		ft_putstr_fd(var_name, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		free(var_name);
		var_name = NULL;
		return (1);
	}
	return (0);
}

int	process_assignment(char *assignment, char ***temp_envp)
{
	char	*var_name;
	char	*expanded_arg;
	int		has_equal;

	var_name = extract_var_name_export(assignment);
	if (!var_name)
	{
		ft_putstr_fd("ShellNote: memory allocation error\n", 2);
		return (free(assignment), assignment = NULL, 0);
	}
	if (handle_invalid_var_name(var_name))
		return (1);
	free(var_name);
	var_name = NULL;
	has_equal = (ft_strchr(assignment, '=') != NULL);
	if (has_equal)
		expanded_arg = expand_assignment_value(assignment);
	else
		expanded_arg = ft_strdup(assignment);
	if (!expanded_arg)
		return (ft_putstr_fd("ShellNote: memory allocation error\n", 2), 
			0);
	*temp_envp = update_or_append_env(*temp_envp, expanded_arg, has_equal);
	return (free(expanded_arg), expanded_arg = NULL, *temp_envp != NULL);
}

char	**process_export_args(char **args, char **envp, int *last_exit_status)
{
	int				i;
	int				error_occurred;
	char			**temp_envp;
	t_export_data	data;

	i = 1;
	error_occurred = 0;
	temp_envp = ft_copy_env(envp);
	if (!temp_envp)
		return (NULL);
	data.envp = envp;
	data.temp_envp = &temp_envp;
	data.last_exit_status = last_exit_status;
	while (args[i] && !error_occurred)
	{
		error_occurred = process_export_arg(args, &i, &data);
		if (!error_occurred)
			i++;
	}
	if (error_occurred)
	{
		free_char_array(temp_envp);
		return (envp);
	}
	return (temp_envp);
}
