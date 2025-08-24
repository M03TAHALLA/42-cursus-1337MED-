/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 09:31:42 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/12 20:53:37 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin_bonus.h"

char	*preserve_quotes_in_value(char *arg, char **envp, int *last_exit_status)
{
	char	*equal_sign;
	char	*var_name;
	char	*var_value;
	char	*result;
	char	*expanded_value;

	equal_sign = ft_strchr(arg, '=');
	if (!equal_sign)
		return (ft_strdup(arg));
	var_name = ft_substr(arg, 0, equal_sign - arg);
	if (!var_name)
		return (NULL);
	var_value = equal_sign + 1;
	expanded_value = expand_argument(var_value, envp, last_exit_status, 0);
	if (!expanded_value)
		return (free(var_name), NULL);
	result = ft_strjoin(var_name, "=");
	free(var_name);
	if (!result)
		return (free(expanded_value), NULL);
	var_name = result;
	result = ft_strjoin(var_name, expanded_value);
	free(var_name);
	free(expanded_value);
	return (result);
}

char	*handle_no_eq_pos(char **args, int i, int *end_idx)
{
	*end_idx = i;
	return (ft_strdup(args[i]));
}

char	*handle_quote_open(char **args, int i, int *end_idx, int quote_open)
{
	char	*result;
	char	*temp;
	char	*last_char;

	result = ft_strdup(args[i]);
	if (!result)
		return (NULL);
	i++;
	while (args[i])
	{
		temp = ft_strjoin(result, " ");
		free(result);
		result = temp;
		temp = ft_strjoin(result, args[i]);
		free(result);
		result = temp;
		last_char = args[i] + ft_strlen(args[i]) - 1;
		if ((quote_open == 2 && *last_char == '"') 
			|| (quote_open == 1 && *last_char == '\''))
			return (*end_idx = i, result);
		i++;
	}
	return (*end_idx = i - 1, result);
}

char	*reconstruct_assignment(char **args, int start_idx, int *end_idx)
{
	char	*eq_pos;
	char	*last_char;
	int		quote_open;

	quote_open = 0;
	eq_pos = ft_strchr(args[start_idx], '=');
	if (!eq_pos || *(eq_pos + 1) == '\0')
		return (handle_no_eq_pos(args, start_idx, end_idx));
	if (!ft_strchr(eq_pos + 1, '"') && !ft_strchr(eq_pos + 1, '\''))
		return (handle_no_eq_pos(args, start_idx, end_idx));
	if (ft_strchr(eq_pos + 1, '"') || ft_strchr(eq_pos + 1, '\''))
	{
		last_char = args[start_idx] + ft_strlen(args[start_idx]) - 1;
		if ((*last_char == '"' && *(eq_pos + 1) == '"') 
			|| (*last_char == '\'' && *(eq_pos + 1) == '\''))
			return (handle_no_eq_pos(args, start_idx, end_idx));
		if (*(eq_pos + 1) == '"')
			quote_open = 2;
		else if (*(eq_pos + 1) == '\'')
			quote_open = 1;
	}
	if (quote_open == 0)
		return (handle_no_eq_pos(args, start_idx, end_idx));
	return (handle_quote_open(args, start_idx, end_idx, quote_open));
}
