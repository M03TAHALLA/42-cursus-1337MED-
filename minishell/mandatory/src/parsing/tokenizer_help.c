/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalyout <fbalyout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:26:52 by fbalyout          #+#    #+#             */
/*   Updated: 2025/05/10 21:39:12 by fbalyout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int	skip_spaces(char *line, int i)
{
	while (line[i] && ft_isspace(line[i]))
		i++;
	return (i);
}

int	count_normal_cmd(char *line)
{
	int		count;
	char	quote;

	if (!line)
		return (0);
	count = 0;
	while (line[count] && !ft_isspace(line[count]) && !ft_strchr("|>&<()",
			line[count]))
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

int	count_tokens(char *line)
{
	int	count;
	int	i;

	if (!line)
		return (0);
	count = 0;
	i = 0;
	while (line[i])
	{
		i = skip_spaces(line, i);
		if (!line[i])
			break ;
		count++;
		if (ft_strchr("|>&<()", line[i]))
		{
			if (line[i + 1] && line[i] == line[i + 1] && ft_strchr("|><&",
					line[i]))
				i += 2;
			else
				i++;
		}
		else
			i += count_normal_cmd(line + i);
	}
	return (count);
}
