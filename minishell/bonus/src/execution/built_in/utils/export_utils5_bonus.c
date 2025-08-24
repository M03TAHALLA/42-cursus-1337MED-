/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:42:27 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/12 20:53:53 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin_bonus.h"

char	*extract_var_name_export(char *arg)
{
	char	*eq_pos;

	eq_pos = ft_strchr(arg, '=');
	if (!eq_pos)
		return (ft_strdup(arg));
	return (ft_substr(arg, 0, eq_pos - arg));
}

char	*join_assignment_parts(char *var_name, char *expanded_value)
{
	char	*result;
	char	*temp;

	result = ft_strjoin(var_name, "=");
	if (!result)
		return (NULL);
	temp = result;
	result = ft_strjoin(temp, expanded_value);
	free(temp);
	return (result);
}

char	*expand_assignment_value(char *assignment)
{
	char	*equal_sign;
	char	*var_name;
	char	*result;

	equal_sign = ft_strchr(assignment, '=');
	if (!equal_sign)
		return (ft_strdup(assignment));
	var_name = ft_substr(assignment, 0, equal_sign - assignment);
	if (!var_name)
		return (NULL);
	result = join_assignment_parts(var_name, equal_sign + 1);
	free(var_name);
	return (result);
}

int	handle_export_prefix(char *arg)
{
	if (ft_strncmp(arg, "export=", 7) == 0)
	{
		ft_putstr_fd("export: `", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		return (1);
	}
	return (0);
}

int	handle_no_equal(char *arg, char ***temp_envp)
{
	if (!is_valid_var_name(arg))
	{
		ft_putstr_fd("export: `", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		return (1);
	}
	*temp_envp = update_or_append_env(*temp_envp, arg, 0);
	if (!*temp_envp)
	{
		ft_putstr_fd("export: memory allocation error\n", 2);
		return (1);
	}
	return (0);
}
