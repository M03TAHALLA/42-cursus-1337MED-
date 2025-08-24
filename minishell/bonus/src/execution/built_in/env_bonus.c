/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:02:39 by mtahalla          #+#    #+#             */
/*   Updated: 2025/04/25 18:49:15 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_bonus.h"

int	count_env_entries(char **envp)
{
	int	count;

	count = 0;
	while (envp && envp[count])
		count++;
	return (count);
}

void	sort_env(char **envp)
{
	int		i;
	int		j;
	int		count;
	char	*tmp;

	if (!envp)
		return ;
	count = count_env_entries(envp);
	if (count <= 1)
		return ;
	i = 0;
	while (i++ < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (ft_strcmp(envp[i], envp[j]) > 0)
			{
				tmp = envp[i];
				envp[i] = envp[j];
				envp[j] = tmp;
			}
			j++;
		}
	}
}

int	is_valid_identifier(char *arg)
{
	int		i;
	char	*equal_sign;

	if (!arg || arg[0] == '\0' || (!ft_isalpha(arg[0]) && arg[0] != '_'))
		return (false);
	equal_sign = ft_strchr(arg, '=');
	if (equal_sign && equal_sign > arg && *(equal_sign - 1) == '+')
		equal_sign--;
	i = 0;
	while (equal_sign && arg + i < equal_sign)
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
			return (false);
		i++;
	}
	if (!equal_sign)
		return (is_valid_var_name(arg));
	return (true);
}

char	**update_or_append_env(char **envp, char *arg, int has_equal)
{
	char	*key;
	char	**updated_envp;
	int		is_append;

	is_append = (ft_strnstr(arg, "+=", ft_strlen(arg)) != NULL);
	key = get_key(arg, has_equal, is_append);
	if (!key)
		return (NULL);
	updated_envp = replace_existing_env(envp, arg, key, has_equal);
	if (updated_envp)
		return (updated_envp);
	return (create_new_env(envp, arg, key, has_equal));
}

int	builtin_env(char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
	{
		if (ft_strchr(env[i], '='))
			printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
