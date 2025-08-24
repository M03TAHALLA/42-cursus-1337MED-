/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalyout <fbalyout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 23:01:40 by fbalyout          #+#    #+#             */
/*   Updated: 2025/05/10 21:39:07 by fbalyout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	count_word(char *line)
{
	int		count;
	char	quote;

	if (!line)
		return (0);
	count = 0;
	while (!ft_strchr("|><&()", line[count]) && line[count]
		&& !ft_isspace(line[count]))
	{
		if (line[count] == '\'' || line[count] == '\"')
		{
			quote = line[count];
			count++;
			while (line[count] && line[count] != quote)
				count++;
			if (line[count])
				count++;
		}
		else
			count++;
	}
	return (count);
}

static void	free_tokens(char **tokens, int count)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (i < count)
		free(tokens[i++]);
	free(tokens);
	tokens = NULL;
}

int	handle_operator(char **tokens, char *line, int *i, int *j)
{
	if (line[*i] == line[*i + 1] && (line[*i] == '>' || line[*i] == '<'
			|| line[*i] == '|' || line[*i] == '&'))
	{
		tokens[*j] = malloc(3 * sizeof(char));
		if (!tokens[*j])
			return (write(2, "malloc on drugs\n", 17), 0);
		tokens[*j][0] = line[*i];
		tokens[*j][1] = line[*i];
		tokens[*j][2] = '\0';
		(*j)++;
		(*i) += 2;
	}
	else
	{
		tokens[*j] = malloc(2 * sizeof(char));
		if (!tokens[*j])
			return (write(2, "malloc on drugs\n", 17), 0);
		tokens[*j][0] = line[*i];
		tokens[*j][1] = '\0';
		(*j)++;
		(*i)++;
	}
	return (1);
}

int	handle_normal_cmd(char **tokens, char *line, int *i, int *j)
{
	int	word_len;
	int	z;

	word_len = count_word(&line[*i]);
	tokens[*j] = malloc((word_len + 1) * sizeof(char));
	if (!tokens[*j])
		return (write(2, "malloc on drugs\n", 17), 0);
	z = 0;
	while (z < word_len)
	{
		tokens[*j][z] = line[*i];
		z++;
		(*i)++;
	}
	tokens[*j][z] = '\0';
	(*j)++;
	return (1);
}

char	**tokinize(char *line)
{
	char	**tokens;
	int		i;
	int		j;

	tokens = malloc((count_tokens(line) + 1) * sizeof(char *));
	if (!tokens)
		return (write(2, "malloc on drugs\n", 17), NULL);
	i = 0;
	j = 0;
	while (line[i])
	{
		while (ft_isspace(line[i]) && line[i])
			i++;
		if (!line[i])
			break ;
		if (ft_strchr("|>&<()", line[i]))
		{
			if (!handle_operator(tokens, line, &i, &j))
				return (free_tokens(tokens, j), NULL);
		}
		else if (!handle_normal_cmd(tokens, line, &i, &j))
			return (free_tokens(tokens, j), NULL);
	}
	return (tokens[j] = NULL, tokens);
}
