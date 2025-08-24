/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:35:53 by mtahalla          #+#    #+#             */
/*   Updated: 2025/04/29 19:35:35 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin_bonus.h"

void	print_str(const char *str)
{
	while (*str)
	{
		write(STDERR_FILENO, str, 1);
		str++;
	}
}

void	print_err(const char *msg, const char *arg)
{
	print_str("ShellNote: exit: ");
	print_str(arg);
	print_str(msg);
}

char	*ft_strjoin_free(char *s1, char *s2, int free_flag)
{
	char	*result;
	size_t	len1;
	size_t	len2;

	len1 = 0;
	len2 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	if (s2)
		len2 = ft_strlen(s2);
	result = (char *)malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);
	if (s1)
		ft_strcpy(result, s1);
	if (s2)
		ft_strcpy(result + len1, s2);
	if (free_flag == 1 || free_flag == 3)
		free(s1);
	if (free_flag == 2 || free_flag == 3)
		free(s2);
	return (result);
}

int	handle_args(char **args, char ***envp)
{
	int		i;
	char	*tmp;

	i = 1;
	while (args[i])
	{
		tmp = args[i];
		args[i] = expand_argument(tmp, *envp, 0, 0);
		free(tmp);
		i++;
	}
	return (0);
}
