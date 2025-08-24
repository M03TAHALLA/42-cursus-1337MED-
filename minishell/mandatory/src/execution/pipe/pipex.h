/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:42:09 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/02 20:48:30 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/stat.h>
# include "utils/utils.h"
# include "../cmd/cmd.h"
# include "../redirection/redirection.h"
# include "../logical_op/op.h"

typedef struct s_data {
	int		i;
	int		fd[2];
	int		pid;
	int		infile;
	int		outfile;
	int		prev_fd;
}	t_data;

typedef struct s_child_args {
	char	*cmd;
	char	**env;
	int		fd_in;
	int		fd_out;
	int		fd_to_close;
}	t_child_args;

typedef struct s_args {
	int		argc;
	char	**argv;
	char	**env;
}	t_args;

typedef struct s_pipeline_data {
	int				num_cmds;
	pid_t			*pids;
	t_ast_node		**nodes;
	int				**pipes;
	int				*state_changing_indexes;
}	t_pipeline_data;

typedef struct s_builtin_parent_data {
	int			*fd;
	pid_t		pidl;
	t_ast_node	*right_cmd;
	char		***envp;
	int			*last_exit_status;
}	t_builtin_parent_data;

typedef struct s_pipeline_data_redir {
	int			fd[2];
	int			pidl;
	int			pidr;
	t_ast_node	*right_cmd;
}	t_pipeline_data_redir;

typedef struct s_builtin_execution_data {
	int			*fd;
	int			pidl;
	t_ast_node	*right_cmd;
	char		***envp;
	int			*last_exit_status;
}	t_builtin_execution_data;

char	*ft_get_path(char *cmd, char **env, int i);
void	free_split(char **split);
char	*execute_script(char *cmd);
char	*join_args(char **args);
size_t	total_len(char **args);
void	execute_command(char *cmd, char **env, int *last_exit_status);
int		execute_complex_pipeline(t_ast_node *node, char ***envp, 
			int *last_exit_status, bool has_pipe);
int		execute_pipeline_with_redirections(t_ast_node *node, char ***envp, 
			int *last_exit_status);
void	handle_error(const char *msg, int fd1, int fd2);
void	close_unused_pipes(t_pipeline_data *data, int num_cmds);
void	execute_from_path(char **args, char **env);
void	execute_direct_path(char **args, char **env);
void	try_execute_path(char **args, char **env);
void	handle_not_found_error(char *path);
void	handle_permission_error(char *path);
void	handle_directory_error(char *path);
void	handle_empty_cmd(char *cmd);
void	free_args(char **args);
void	cleanup_heredocs(t_pipeline_data *data);
int		is_state_changing_builtin(char *cmd);
void	apply_state_changes(t_pipeline_data *data, char ***envp,
			int *last_exit_status);
pid_t	prepare_right_child(int *fd, t_ast_node *right_node, 
			char ***envp, int *last_exit_status);
int		handle_builtin_parent(t_builtin_parent_data *data);
pid_t	prepare_left_child(int *fd, t_ast_node *left_node, 
			char ***envp, int *last_exit_status);
int		is_state_changing_right_cmd(t_ast_node *node);
int		handle_complex_right_pipe(t_ast_node *node, char ***envp, 
			int *last_exit_status);
int		help_dquote(char *str, int *i);
int		handle_builtin_execution(t_builtin_execution_data *exec_data);

#endif