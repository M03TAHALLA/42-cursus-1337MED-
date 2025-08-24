/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 09:59:23 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/02 20:14:07 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "../pipe/pipex.h"
# include "../../wild_cards/wild_card.h"

typedef struct s_quote_state
{
	int	in_single_quote;
	int	in_double_quote;
}	t_quote_state;

typedef struct s_exec_context
{
	char	***envp;
	int		*last_exit_status;
	bool	has_pipe;
	int		original_fds[3];
}	t_exec_context;

int		process_with_redirections(t_ast_node *node, char **env,
			int *last_exit_status);
int		execute_cmd_with_redirections(t_ast_node *root, char ***envp, 
			int *last_exit_status, bool has_pipe);
char	**expand_wildcards_in_args(char **args);
int		count_expanded_args(char **args);
int		process_wildcard_arg(char **args, int i, int *new_size);
int		count_matches(char **matches, char *arg);
char	*remove_quotes(const char *pattern);
void	handle_child_process(t_ast_node *node, char **env,
			int *last_exit_status);
int		improved_match(const char *pattern, const char *str);
char	*allocate_result(const char *pattern);
void	handle_quote(int *in_quotes, char *quote_char, char c, int *i);
void	fill_expanded_args(char **expanded_args, char **args,
			char **wildcard_matches, int *k);
void	add_matched_args(char **expanded_args, char **matches,
			char *arg, int *k);
size_t	ft_strfound(const char *str, const char *accept);
void	save_original_fds(int original_fds[3]);
void	restore_original_fds(int original_fds[3]);

#endif