/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:38:40 by mtahalla          #+#    #+#             */
/*   Updated: 2025/04/29 16:56:58 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_BONUS_H
# define OP_BONUS_H

# include "../pipe/pipex_bonus.h"

int	execute_logical_operator_with_redirections(t_ast_node *root, 
		char ***envp, bool has_pipe, int *last_exit_status);
int	execute_node_with_redirections(t_ast_node *node, 
		char ***envp, bool has_pipe, int *last_exit_status);

#endif