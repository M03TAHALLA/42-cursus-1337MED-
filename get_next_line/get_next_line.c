/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:53:18 by mtahalla          #+#    #+#             */
/*   Updated: 2024/11/15 20:38:31 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*join_buffer(char *result, char *buffer)
{
	char	*new_buffer;

	new_buffer = ft_strjoin(result, buffer);
	free(result);
	return (new_buffer);
}

static char	*read_to_buffer(int fd, char *result)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(result), result = NULL, NULL);
	while (!ft_strchr(result, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (free(buffer), result);
		buffer[bytes_read] = '\0';
		result = join_buffer(result, buffer);
		if (!result)
			return (free(buffer), NULL);
	}
	return (free(buffer), result);
}

static char	*extract_line_from_buffer(char **result)
{
	char	*line;
	char	*new_buffer;
	size_t	len;

	len = ft_strchr(*result, '\n') - *result + 1;
	line = ft_strndup(*result, len);
	new_buffer = ft_strdup(*result + len);
	free(*result);
	*result = new_buffer;
	if (!line || (*result && !**result))
		return (free(*result), *result = NULL, line);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*result;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (free(result), result = NULL, NULL);
	if (!result)
		result = ft_strdup("");
	if (!result)
		return (NULL);
	result = read_to_buffer(fd, result);
	if (!result || result[0] == '\0')
		return (free(result), result = NULL, NULL);
	if (ft_strchr(result, '\n'))
		line = extract_line_from_buffer(&result);
	else
	{
		line = ft_strdup(result);
		free(result);
		result = NULL;
	}
	return (line);
}
