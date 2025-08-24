/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:27:39 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/12 20:48:13 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin.h"

char	*join_args_with_space(char **args, int start_index)
{
	char	*result;
	char	*temp;
	int		i;

	result = NULL;
	i = start_index;
	while (args[i])
	{
		if (!result)
			result = ft_strdup(args[i]);
		else
		{
			temp = ft_strjoin(result, " ");
			free(result);
			result = ft_strjoin_free(temp, args[i], 1);
		}
		i++;
	}
	return (result);
}

static char	**copy_env(char **envp, int count)
{
	char	**envp_copy;
	int		i;

	envp_copy = malloc((count + 1) * sizeof(char *));
	if (!envp_copy)
		return (NULL);
	i = 0;
	while (i < count)
	{
		envp_copy[i] = ft_strdup(envp[i]);
		if (!envp_copy[i])
		{
			while (--i >= 0)
				free(envp_copy[i]);
			free(envp_copy);
			return (NULL);
		}
		i++;
	}
	envp_copy[count] = NULL;
	return (envp_copy);
}

void	print_sorted_env(char **envp)
{
	int		count;
	char	**envp_copy;
	int		i;

	count = 0;
	while (envp && envp[count])
		count++;
	if (count == 0)
		return ;
	envp_copy = copy_env(envp, count);
	if (!envp_copy)
		return ;
	sort_env(envp_copy);
	i = 0;
	while (i < count && envp_copy[i])
	{
		print_env_entry(envp_copy[i]);
		free(envp_copy[i]);
		i++;
	}
	free(envp_copy);
}

void	free_old_env(char **envp)
{
	int	j;

	j = 0;
	while (envp && envp[j])
	{
		free(envp[j]);
		envp[j] = NULL;
		j++;
	}
	free(envp);
	envp = NULL;
}

char	**create_new_env(char **envp, char *arg, char *key, int has_equal)
{
	char	**new_envp;
	int		size;
	char	*entry_to_add;

	new_envp = allocate_new_env(envp, &size);
	if (!new_envp)
	{
		free(key);
		return (NULL);
	}
	if (has_equal)
		entry_to_add = arg;
	else
		entry_to_add = key;
	copy_and_add_entry(new_envp, envp, entry_to_add, size);
	free(key);
	free_old_env(envp);
	return (new_envp);
}
