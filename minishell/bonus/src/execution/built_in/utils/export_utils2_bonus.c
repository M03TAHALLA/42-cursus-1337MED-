/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:31:59 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/12 20:46:23 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin_bonus.h"

char	*get_key(const char *arg, int has_equal, int is_append)
{
	char	*delimiter;

	if (has_equal)
	{
		if (is_append)
			delimiter = ft_strchr(arg, '+');
		else
			delimiter = ft_strchr(arg, '=');
		return (ft_substr(arg, 0, delimiter - arg));
	}
	return (ft_strdup(arg));
}

char	*append_env_value(char *key, char *arg)
{
	char	*existing_value;
	char	*new_value;
	char	*temp;
	char	*result;

	existing_value = ft_strchr(arg, '=') + 1;
	new_value = ft_strjoin(key, "=");
	temp = ft_strjoin(existing_value, ft_strchr(arg, '=') + 1);
	result = ft_strjoin_free(new_value, temp, 3);
	return (result);
}

void	update_existing_entry(char **envp, int i, char *arg, 
	int is_append)
{
	char	*key;
	char	*new_value;

	if (is_append)
	{
		key = ft_strndup(envp[i], ft_strchr(envp[i], '=') - envp[i]);
		new_value = append_env_value(key, arg);
		free(key);
		key = NULL;
		free(envp[i]);
		envp[i] = NULL;
		envp[i] = new_value;
	}
	else
	{
		free(envp[i]);
		envp[i] = NULL;
		envp[i] = ft_strdup(arg);
	}
}

char	**replace_existing_env(char **envp, char *arg, char *key,
	int has_equal)
{
	size_t	len;
	int		is_append;
	int		i;

	len = ft_strlen(key);
	is_append = (ft_strnstr(arg, "+=", ft_strlen(arg)) != NULL);
	i = 0;
	while (envp && envp[i])
	{
		if (!ft_strncmp(envp[i], key, len) 
			&& (envp[i][len] == '=' || envp[i][len] == '\0'))
		{
			if (has_equal)
				update_existing_entry(envp, i, arg, is_append);
			free(key);
			return (envp);
		}
		i++;
	}
	return (NULL);
}

char	**allocate_new_env(char **envp, int *size)
{
	char	**new_envp;
	int		i;

	i = 0;
	while (envp && envp[i])
		i++;
	*size = i;
	new_envp = malloc(sizeof(char *) * (i + 2));
	return (new_envp);
}
