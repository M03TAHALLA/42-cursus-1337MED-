/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:48:50 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/12 20:50:47 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin.h"

void	append_char(char **res, char c)
{
	size_t	len;
	char	*new;

	if (*res)
		len = ft_strlen(*res);
	else
		len = 0;
	new = malloc(len + 2);
	if (!new)
		return ;
	if (*res)
		ft_strcpy(new, *res);
	new[len] = c;
	new[len + 1] = '\0';
	free(*res);
	*res = new;
}

void	append_str(char **res, char *str)
{
	size_t	len1;
	size_t	len2;
	char	*new;

	if (*res)
		len1 = ft_strlen(*res);
	else
		len1 = 0;
	len2 = ft_strlen(str);
	new = malloc(len1 + len2 + 1);
	if (!new)
		return ;
	if (*res)
		ft_strcpy(new, *res);
	ft_strcpy(new + len1, str);
	free(*res);
	*res = new;
}

void	handle_single_quotes(const char *input, char **result, int *i)
{
	(*i)++;
	while (input[*i] && input[*i] != '\'')
		append_char(result, input[(*i)++]);
	if (input[*i] == '\'')
		(*i)++;
}

void	handle_exit_status(char **result, int *i, t_expand_context *ctx)
{
	char	*exit_str;

	exit_str = ft_itoa(*(ctx->last_exit_status));
	if (exit_str)
	{
		append_str(result, exit_str);
		free(exit_str);
		exit_str = NULL;
	}
	(*i)++;
}

int	process_export_arg(char **args, int *i, t_export_data *data)
{
	char	*equal_pos;
	char	*assignment;
	int		end_idx;

	if (ft_strcmp(args[0], "export") == 0 && handle_export_prefix(args[*i]))
		return (1);
	equal_pos = ft_strchr(args[*i], '=');
	if (!equal_pos)
		return (handle_no_equal(args[*i], data->temp_envp));
	assignment = reconstruct_assignment(args, *i, &end_idx);
	if (!assignment)
	{
		ft_putstr_fd("export: memory allocation error\n", 2);
		*i = end_idx;
		return (0);
	}
	if (!process_assignment(assignment, data->temp_envp))
		return (*i = end_idx, 0);
	free(assignment);
	assignment = NULL;
	*i = end_idx;
	return (0);
}
