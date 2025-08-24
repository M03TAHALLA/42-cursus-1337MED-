/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:52:25 by mtahalla          #+#    #+#             */
/*   Updated: 2025/04/29 19:42:45 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static void	print_invalid_identifier_error(char *var_name)
{
	ft_putstr_fd("ShellNote unset: `", 2);
	ft_putstr_fd(var_name, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
}

static void	remove_env_var(char *var_name, char ***envp)
{
	size_t	len;
	int		j;
	int		k;

	len = ft_strlen(var_name);
	j = 0;
	while ((*envp)[j])
	{
		if (!ft_strncmp((*envp)[j], var_name, len) &&
			((*envp)[j][len] == '=' || (*envp)[j][len] == '\0'))
		{
			free((*envp)[j]);
			k = j;
			while ((*envp)[k + 1])
			{
				(*envp)[k] = (*envp)[k + 1];
				k++;
			}
			(*envp)[k] = NULL;
			return ;
		}
		j++;
	}
}

int	builtin_unset(char **args, char ***envp)
{
	int	i;

	if (!args || !args[1] || !envp || !*envp)
		return (1);
	i = 1;
	while (args[i])
	{
		if (!is_valid_var_name(args[i]))
			print_invalid_identifier_error(args[i]);
		else
			remove_env_var(args[i], envp);
		i++;
	}
	return (0);
}
