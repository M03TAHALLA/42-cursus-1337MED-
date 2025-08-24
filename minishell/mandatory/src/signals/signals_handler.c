/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalyout <fbalyout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 09:04:49 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/23 13:19:47 by fbalyout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

extern pid_t	g_shell_state;

void	handle_signal(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		if (g_shell_state == 0)
		{
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
	}
	else if (sig == SIGQUIT)
	{
		if (g_shell_state == 1)
			write(1, "Quit: 3\n", 8);
		else
			return ;
	}
}

void	setup_signals(void)
{
	struct sigaction	sa;

	sa.sa_handler = handle_signal;
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &sa, NULL) == -1)
		perror("sigaction");
	if (g_shell_state == 0)
	{
		signal(SIGQUIT, SIG_IGN);
	}
	else
	{
		if (sigaction(SIGQUIT, &sa, NULL) == -1)
			perror("sigaction");
	}
}

void	set_interactive_mode(void)
{
	g_shell_state = 0;
	signal(SIGQUIT, SIG_IGN);
}

void	set_execution_mode(void)
{
	struct sigaction	sa;

	g_shell_state = 1;
	sa.sa_handler = handle_signal;
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGQUIT, &sa, NULL) == -1)
		perror("sigaction");
}

void	restore_default_signals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
