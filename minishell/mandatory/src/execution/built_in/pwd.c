/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:48:26 by mtahalla          #+#    #+#             */
/*   Updated: 2025/04/29 19:41:48 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	builtin_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		perror("pwd");
		return (1);
	}
	printf("%s\n", cwd);
	free(cwd);
	return (0);
}

void	print_env_entry(char *entry)
{
	char	*eq;
	int		name_len;

	printf("declare -x ");
	eq = ft_strchr(entry, '=');
	if (eq)
	{
		name_len = eq - entry;
		printf("%.*s=\"%s\"\n", name_len, entry, eq + 1);
	}
	else
		printf("%s\n", entry);
}

void	copy_and_add_entry(char **new_envp, char **envp, char *entry, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		new_envp[j] = ft_strdup(envp[j]);
		j++;
	}
	new_envp[size] = ft_strdup(entry);
	new_envp[size + 1] = NULL;
}
