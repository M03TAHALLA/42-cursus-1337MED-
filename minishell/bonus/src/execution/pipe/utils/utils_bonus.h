/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:41:01 by mtahalla          #+#    #+#             */
/*   Updated: 2025/04/30 12:02:53 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include "../../../../minishell_bonus.h"

char	**ft_split_args(char const *s, char c);
char	**allocate_strings(char const *s, char c);
int		count_strings(char const *s, char sep);
void	skip_separator(char const **s, char sep, int *in_quotes);
void	skip_word(char const **s, char sep, int *in_quotes);
char	**ft_split_pipe(char const *s, char c);
char	*ft_strjoin_pipe(char const *s1, char const *s2);
size_t	ft_strlcpy_pipe(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen_pipe(const char *s);
int		ft_strcmp_pipe(const char *s1, const char *s2);
char	*ft_strnstr_pipe(const char *haystack, const char *needle, size_t len);
void	free_args(char **args);
char	**free_split_args(char **strings, int i);
void	handle_quoted_string(const char **s, char **strings, int *i);

#endif
