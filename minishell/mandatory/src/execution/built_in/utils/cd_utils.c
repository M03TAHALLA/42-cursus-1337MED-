/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:23:06 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/01 15:41:34 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin.h"

char	*create_env_var(const char *name, const char *value, size_t name_len)
{
	char	*new_var;
	size_t	total_len;

	total_len = name_len + ft_strlen(value) + 2;
	new_var = malloc(total_len);
	if (new_var)
	{
		ft_strlcpy(new_var, name, name_len + 1);
		new_var[name_len] = '=';
		ft_strlcpy(new_var + name_len + 1, value, total_len - name_len - 1);
	}
	return (new_var);
}

void	update_env(const char *name, const char *value, char **envp)
{
	int		i;
	size_t	name_len;
	char	*new_var;

	i = 0;
	name_len = ft_strlen(name);
	while (envp && envp[i])
	{
		if (ft_strncmp(envp[i], name, name_len) == 0 
			&& envp[i][name_len] == '=')
		{
			new_var = create_env_var(name, value, name_len);
			if (new_var)
				envp[i] = new_var;
			return ;
		}
		i++;
	}
}

int	handle_home_case(char **target, char **envp, char *oldpwd)
{
	*target = get_env_value("HOME", envp);
	if (!*target)
	{
		write(2, "cd: HOME not set\n", 17);
		free(oldpwd);
		return (1);
	}
	return (0);
}

int	handle_oldpwd_case(char **target, char **envp, char *oldpwd)
{
	*target = get_env_value("OLDPWD", envp);
	if (!*target)
	{
		write(2, "cd: OLDPWD not set\n", 19);
		free(oldpwd);
		return (1);
	}
	printf("%s\n", *target);
	return (0);
}
