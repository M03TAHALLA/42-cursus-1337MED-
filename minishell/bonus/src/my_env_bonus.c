/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_env_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalyout <fbalyout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 09:00:23 by fbalyout          #+#    #+#             */
/*   Updated: 2025/05/22 16:15:05 by fbalyout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"

void	free_env(char **env, int i)
{
	while (i > 0)
	{
		free(env[i]);
		env[i] = NULL;
		i--;
	}
	free(env);
	env = NULL;
}

char	**get_env(char **env)
{
	char	**my_env;
	int		i;
	int		size;

	if (!env)
		return (NULL);
	size = 0;
	while (env[size])
		size++;
	my_env = (char **)malloc(sizeof(char *) * (size + 1));
	if (!my_env)
		return (NULL);
	i = 0;
	while (i < size)
	{
		my_env[i] = ft_strdup(env[i]);
		if (!my_env[i])
		{
			free_env(env, i);
			return (NULL);
		}
		i++;
	}
	my_env[size] = NULL;
	return (my_env);
}

void	free_env1(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		free(env[i]);
		env[i] = NULL;
		i++;
	}
	free(env);
}

void	handle_hrdoc(int sig)
{
	(void)sig;
	exit(1);
}
