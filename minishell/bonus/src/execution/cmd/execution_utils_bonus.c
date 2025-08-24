/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 22:11:33 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/12 21:21:51 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_bonus.h"

char	*remove_quotes(const char *pattern)
{
	char	*result;
	int		i;
	int		j;
	int		in_quotes;
	char	quote_char;

	in_quotes = 0;
	quote_char = '\0';
	result = allocate_result(pattern);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (pattern[i])
	{
		if ((pattern[i] == '\'' || pattern[i] == '\"')
			&& (!in_quotes || quote_char == pattern[i]))
		{
			handle_quote(&in_quotes, &quote_char, pattern[i], &i);
			continue ;
		}
		result[j++] = pattern[i++];
	}
	result[j] = '\0';
	return (result);
}

int	count_matches(char **matches, char *arg)
{
	int		j;
	int		count;
	char	*unquoted_pattern;

	j = 0;
	count = 0;
	if (!matches)
		return (0);
	while (matches[j])
	{
		unquoted_pattern = remove_quotes(arg);
		if (improved_match(unquoted_pattern, matches[j]))
			count++;
		free(unquoted_pattern);
		j++;
	}
	return (count);
}

int	process_wildcard_arg(char **args, int i, int *new_size)
{
	char	*unquoted_pattern;
	char	**wildcard_matches;
	int		matches_in_current;

	matches_in_current = 0;
	unquoted_pattern = remove_quotes(args[i]);
	if (!unquoted_pattern)
		return (-1);
	wildcard_matches = wild_cards(unquoted_pattern);
	free(unquoted_pattern);
	matches_in_current = count_matches(wildcard_matches, args[i]);
	if (wildcard_matches)
		free_args(wildcard_matches);
	if (matches_in_current > 0)
		*new_size += matches_in_current;
	else
		(*new_size)++;
	return (0);
}

int	count_expanded_args(char **args)
{
	int		i;
	int		new_size;
	int		result;

	i = 0;
	new_size = 0;
	while (args[i])
	{
		if (ft_strchr(args[i], '*'))
		{
			if ((args[i][0] == '\'' && args[i][ft_strlen(args[i]) - 1] == '\'') 
			|| (args[i][0] == '\"' && args[i][ft_strlen(args[i]) - 1] == '\"'))
				return (-1);
			result = process_wildcard_arg(args, i, &new_size);
			if (result == -1)
				return (-1);
		}
		else
			new_size++;
		i++;
	}
	return (new_size);
}

size_t	ft_strfound(const char *str, const char *accept)
{
	size_t	i;
	size_t	j;
	int		found;

	if (!str || !accept)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		found = 0;
		j = 0;
		while (accept[j] != '\0')
		{
			if (str[i] == accept[j])
			{
				found = 1;
				break ;
			}
			j++;
		}
		if (!found)
			break ;
		i++;
	}
	return (i);
}
