/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:20:34 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/01 17:41:43 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_BONUS_H
# define BUILTIN_BONUS_H

# include "../../../minishell_bonus.h"
# include "../pipe/utils/utils_bonus.h"
# include <limits.h>
# include <errno.h>
# include <string.h>

typedef struct s_expand_context
{
	char	**envp;
	int		*last_exit_status;
	int		*finder;
}	t_expand_context;

typedef struct s_export_data
{
	char	**envp;
	char	***temp_envp;
	int		*last_exit_status;
}	t_export_data;

bool	is_builtin(char *cmd);
char	*expand_argument(const char *input, char **envp, int *last_exit_status,
			int *finder);
int		execute_builtin(t_ast_node *node, char ***envp, 
			int last_exit_status, bool has_pipe);
char	*reconstruct_assignment(char **args, int start_idx, int *end_idx);
char	**ft_copy_env(char **envp);
char	*preserve_quotes_in_value(char *arg, char **envp, 
			int *last_exit_status);
void	free_char_array(char **array);
char	**process_export_args(char **args, char **envp, int *last_exit_status);
int		builtin_echo(char **args, int *last_exit_status, char ***envp);
void	print_env_entry(char *entry);
void	copy_and_add_entry(char **new_envp, char **envp, char *entry, int size);
int		builtin_cd(char **args, char **envp, int last_exit_status);
int		change_directory(char *target, char *oldpwd, char **envp);
int		handle_env_var(char **args, char **target, char *oldpwd,
			char **envp);
int		handle_special_cases(char **args, char **envp, char **target,
			char *oldpwd);
void	update_env(const char *name, const char *value, char **envp);
char	*create_env_var(const char *name, const char *value, size_t name_len);
void	handle_exit_status(char **result, int *i, t_expand_context *ctx);
void	handle_single_quotes(const char *input, char **result, int *i);
char	*extract_var_name(char *arg);
void	append_char(char **res, char c);
void	append_str(char **res, char *str);
int		handle_env_var_error(char *arg, char *oldpwd);
int		handle_home_case(char **target, char **envp, char *oldpwd);
int		handle_oldpwd_case(char **target, char **envp, char *oldpwd);
char	*get_env_value(const char *name, char **env);
int		builtin_pwd(void);
int		builtin_export(char *cmd, char ***envp, int last_exit_status);
char	*join_args_with_space(char **args, int start_index);
char	*ft_strjoin_free(char *s1, char *s2, int free_flag);
void	free_old_env(char **envp);
char	**create_new_env(char **envp, char *arg, char *key, int has_equal);
void	print_env_entry(char *entry);
void	copy_and_add_entry(char **new_envp, char **envp, char *entry,
			int size);
char	**update_or_append_env(char **envp, char *arg, int has_equal);
char	**allocate_new_env(char **envp, int *size);
char	**replace_existing_env(char **envp, char *arg, char *key,
			int has_equal);
void	update_existing_entry(char **envp, int i, char *arg, int is_append);
int		is_valid_identifier(char *s);
int		is_valid_var_name(char *name);
char	*get_key(const char *arg, int has_equal, int is_append);
char	*append_env_value(char *key, char *arg);
int		builtin_env(char **env);
void	sort_env(char **envp);
void	print_sorted_env(char **envp);
int		builtin_exit(char **args, int last_exit_status, bool has_pipe);
void	print_err(const char *msg, const char *arg);
void	print_str(const char *str);
int		builtin_unset(char **args, char ***envp);
int		process_export_arg(char **args, int *i, t_export_data *data);
char	*extract_var_name_export(char *arg);
char	*join_assignment_parts(char *var_name, char *expanded_value);
char	*expand_assignment_value(char *assignment);
int		handle_export_prefix(char *arg);
int		handle_no_equal(char *arg, char ***temp_envp);
int		process_assignment(char *assignment, char ***temp_envp);
int		handle_args(char **args, char ***envp);
#endif