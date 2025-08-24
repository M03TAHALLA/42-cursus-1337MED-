/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:27:43 by mtahalla          #+#    #+#             */
/*   Updated: 2025/04/25 11:28:40 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"

int	handle_redirection_error(char *message)
{
	write(2, message, ft_strlen(message));
	return (-1);
}

int	open_and_dup_input(char *filetrimmed)
{
	int	fd;

	fd = open(filetrimmed, O_RDONLY);
	if (fd < 0 || dup2(fd, STDIN_FILENO) == -1)
	{
		perror("ShellNote");
		if (fd >= 0)
			close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}

int	handle_input_redirection(char *file)
{
	char	*filetrimmed;

	filetrimmed = ft_strtrim(file, " ");
	if (!filetrimmed)
		return (0);
	if (open_and_dup_input(filetrimmed) == -1)
	{
		free(filetrimmed);
		return (-1);
	}
	free(filetrimmed);
	return (0);
}
