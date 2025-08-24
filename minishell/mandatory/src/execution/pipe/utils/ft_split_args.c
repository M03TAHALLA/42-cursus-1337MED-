/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 23:21:42 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/04 23:21:42 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	count_args(const char *s, char c)
{
	int	count;
	int	in_single_quote;
	int	in_double_quote;
	int	in_word;

	count = 0;
	in_single_quote = 0;
	in_double_quote = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == '\'' && !in_double_quote)
			in_single_quote = !in_single_quote;
		else if (*s == '"' && !in_single_quote)
			in_double_quote = !in_double_quote;
		if (!in_single_quote && !in_double_quote && *s == c && in_word)
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static char	*extract_word(const char **s, char c)
{
	const char	*start;
	char		*word;
	int			len;
	int			in_single_quote;
	int			in_double_quote;

	start = *s;
	len = 0;
	in_single_quote = 0;
	in_double_quote = 0;
	while (**s && (in_single_quote || in_double_quote || **s != c))
	{
		if (**s == '\'' && !in_double_quote)
			in_single_quote = !in_single_quote;
		else if (**s == '"' && !in_single_quote)
			in_double_quote = !in_double_quote;
		len++;
		(*s)++;
	}
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	ft_strncpy(word, start, len);
	word[len] = '\0';
	return (word);
}

static void	free_result(char **result, int arg_idx)
{
	while (arg_idx > 0)
		free(result[--arg_idx]);
	free(result);
}

static int	fill_result(char **result, char const *s, char c, int arg_count)
{
	int	arg_idx;

	arg_idx = 0;
	while (*s && *s == c)
		s++;
	while (*s && arg_idx < arg_count)
	{
		if (*s == c)
		{
			s++;
			continue ;
		}
		result[arg_idx] = extract_word(&s, c);
		if (!result[arg_idx])
		{
			free_result(result, arg_idx);
			return (0);
		}
		arg_idx++;
	}
	result[arg_idx] = NULL;
	return (1);
}

char	**ft_split_args(char const *s, char c)
{
	char	**result;
	int		arg_count;

	if (!s)
		return (NULL);
	arg_count = count_args(s, c);
	result = (char **)malloc(sizeof(char *) * (arg_count + 1));
	if (!result)
		return (NULL);
	if (!fill_result(result, s, c, arg_count))
		return (NULL);
	return (result);
}
