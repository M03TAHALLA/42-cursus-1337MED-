/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 08:34:47 by mtahalla          #+#    #+#             */
/*   Updated: 2025/04/29 12:58:39 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

size_t	total_len(char **args)
{
	size_t	len;
	int		i;

	len = 0;
	i = 0;
	while (args[i])
	{
		len += ft_strlen(args[i]);
		if (args[i + 1])
			len++;
		i++;
	}
	return (len);
}

char	*join_args(char **args)
{
	size_t	len;
	char	*joined;
	int		i;

	i = 0;
	if (!args || !*args)
		return (NULL);
	len = total_len(args);
	joined = malloc(len + 1);
	if (!joined)
		return (NULL);
	joined[0] = '\0';
	while (args[i])
	{
		ft_strcat(joined, args[i]);
		if (args[i + 1])
			ft_strcat(joined, " ");
		i++;
	}
	return (joined);
}
