/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:53:24 by mtahalla          #+#    #+#             */
/*   Updated: 2024/11/15 20:51:02 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoinget(char *s1, char *s2);
char	*ft_strdupget(char *src);
char	*ft_strchrget(char *s, int c);
char	*ft_strndupget(const char *s, size_t n);
char	*ft_strcpyget(char *dst, const char *src);

#endif