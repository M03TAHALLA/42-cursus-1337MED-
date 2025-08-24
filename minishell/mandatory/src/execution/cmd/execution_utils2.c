/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:12:12 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/12 21:22:41 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

void	add_matched_args(char **expanded_args, char **matches,
				char *arg, int *k)
{
	int		j;
	char	*unquoted_pattern;

	if (!matches)
		return ;
	j = 0;
	while (matches[j])
	{
		unquoted_pattern = remove_quotes(arg);
		if (improved_match(unquoted_pattern, matches[j]))
			expanded_args[(*k)++] = ft_strdup(matches[j]);
		free(unquoted_pattern);
		j++;
	}
}

int	improved_match(const char *pattern, const char *str)
{
	if (!*pattern)
		return (!*str);
	while (*pattern && *str)
	{
		if (*pattern == '*')
		{
			pattern++;
			if (!*pattern)
				return (1);
			while (*str)
			{
				if (improved_match(pattern, str))
					return (1);
				str++;
			}
			return (0);
		}
		else if (*pattern != *str)
			return (0);
		pattern++;
		str++;
	}
	while (*pattern == '*')
		pattern++;
	return (*pattern == '\0' && *str == '\0');
}

void	fill_expanded_args(char **expanded_args, char **args,
					char **wildcard_matches, int *k)
{
	int		i;
	int		matches_in_current;
	char	*unquoted_pattern;

	i = 0;
	while (args[i])
	{
		matches_in_current = 0;
		if (ft_strchr(args[i], '*'))
		{
			unquoted_pattern = remove_quotes(args[i]);
			if (!unquoted_pattern)
				return ;
			wildcard_matches = wild_cards(unquoted_pattern);
			free(unquoted_pattern);
			add_matched_args(expanded_args, wildcard_matches, args[i], k);
			matches_in_current = count_matches(wildcard_matches, args[i]);
			if (wildcard_matches)
				free_args(wildcard_matches);
		}
		if (matches_in_current == 0)
			expanded_args[(*k)++] = ft_strdup(args[i]);
		i++;
	}
}

char	**expand_wildcards_in_args(char **args)
{
	int		new_size;
	char	**expanded_args;
	int		k;

	new_size = count_expanded_args(args);
	if (new_size == -1)
		return (args);
	expanded_args = malloc((new_size + 1) * sizeof(char *));
	if (!expanded_args)
		return (args);
	k = 0;
	fill_expanded_args(expanded_args, args, NULL, &k);
	expanded_args[k] = NULL;
	free_args(args);
	return (expanded_args);
}

int	process_with_redirections(t_ast_node *node, char **env,
		int *last_exit_status)
{
	int		pid;

	set_execution_mode();
	pid = fork();
	if (pid < 0)
		exit(1);
	if (pid == 0)
		handle_child_process(node, env, last_exit_status);
	return (pid);
}
