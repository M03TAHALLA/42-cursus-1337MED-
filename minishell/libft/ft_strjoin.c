/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalyout <fbalyout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:07:04 by fbalyout          #+#    #+#             */
/*   Updated: 2024/10/26 16:07:04 by fbalyout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*string;

	if (!s1 || !s2)
		return (ft_strdup(""));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	string = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!string)
		return (NULL);
	ft_strlcpy(string, s1, len_s1 + 1);
	ft_strlcat(string, s2, len_s1 + len_s2 + 1);
	return (string);
}
