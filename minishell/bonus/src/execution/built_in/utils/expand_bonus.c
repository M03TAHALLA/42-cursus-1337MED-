/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:31:29 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/01 17:31:02 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin_bonus.h"

static void	handle_variable_expand(const char *input, char **result, int *i, 
		t_expand_context *ctx)
{
	char	*var;
	char	*val;
	int		start;

	start = *i;
	while (input[*i] && (ft_isalnum(input[*i]) || input[*i] == '_'))
		(*i)++;
	var = ft_substr(input, start, *i - start);
	if (var)
	{
		val = get_env_value(var, ctx->envp);
		if (val)
		{
			append_str(result, val);
			free(val);
		}
		else if (ctx->finder)
			*(ctx->finder) = 1;
		free(var);
	}
}

static void	handle_dollar(const char *input, char **result, int *i, 
		t_expand_context *ctx)
{
	(*i)++;
	if (input[*i] == '?')
		handle_exit_status(result, i, ctx);
	else
		handle_variable_expand(input, result, i, ctx);
}

static void	handle_double_quotes(const char *input, char **result, int *i, 
		t_expand_context *ctx)
{
	(*i)++;
	while (input[*i] && input[*i] != '"')
	{
		if (input[*i] == '$')
			handle_dollar(input, result, i, ctx);
		else
			append_char(result, input[(*i)++]);
	}
	if (input[*i] == '"')
		(*i)++;
}

static void	process_input(const char *input, char **result, int *i, 
		t_expand_context *ctx)
{
	while (input[*i])
	{
		if (input[*i] == '\'')
			handle_single_quotes(input, result, i);
		else if (input[*i] == '"')
			handle_double_quotes(input, result, i, ctx);
		else if (input[*i] == '$')
			handle_dollar(input, result, i, ctx);
		else
			append_char(result, input[(*i)++]);
	}
}

char	*expand_argument(const char *input, char **envp, int *last_exit_status, 
		int *finder)
{
	char				*result;
	int					i;
	t_expand_context	ctx;

	ctx.envp = envp;
	ctx.last_exit_status = last_exit_status;
	ctx.finder = finder;
	result = ft_strdup("\0");
	i = 0;
	if (finder)
		*finder = 0;
	process_input(input, &result, &i, &ctx);
	return (result);
}
