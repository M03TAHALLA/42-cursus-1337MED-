/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wild_card_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalyout <fbalyout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 09:20:15 by fbalyout          #+#    #+#             */
/*   Updated: 2025/05/18 15:33:11 by fbalyout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

char	**prepare_wildcard_matching(void)
{
	char	**matched_files;

	matched_files = malloc(MAX_FILES * sizeof(char *));
	if (!matched_files)
	{
		perror("malloc");
		return (NULL);
	}
	return (matched_files);
}

DIR	*try_open_current_dir(void)
{
	DIR	*dir;

	dir = opendir(".");
	if (dir == NULL)
		perror("opendir");
	return (dir);
}

int	save_matching_file(char **results, char *filename, int count, DIR *dir)
{
	char	*duplicate;

	duplicate = ft_strdup(filename);
	if (!duplicate)
	{
		free(results);
		closedir(dir);
		return (-1);
	}
	results[count] = duplicate;
	if (!results[count])
	{
		free(duplicate);
		return (-1);
	}
	return (count + 1);
}

int	find_matching_files(DIR *dir, char **results, char *pattern)
{
	struct dirent	*entry;
	int				count;
	char			*filename;

	count = 0;
	entry = readdir(dir);
	while (entry != NULL)
	{
		filename = entry->d_name;
		entry = readdir(dir);
		if (!filename || (filename[0] == '.' && pattern[0] != '.'))
			continue ;
		if (check_wild_card(filename, pattern))
		{
			count = save_matching_file(results, filename, count, dir);
			if (count < 0)
				return (-1);
			if (count >= MAX_FILES)
			{
				ft_putstr_fd("Too many files\n", 2);
				break ;
			}
		}
	}
	return (count);
}

char	**wild_cards(char *pattern)
{
	DIR		*dir;
	char	**results;
	int		match_count;

	results = prepare_wildcard_matching();
	if (!results)
		return (NULL);
	dir = try_open_current_dir();
	if (dir == NULL)
	{
		free(results);
		return (NULL);
	}
	match_count = find_matching_files(dir, results, pattern);
	closedir(dir);
	if (match_count < 0)
		return (NULL);
	results[match_count] = NULL;
	return (results);
}
