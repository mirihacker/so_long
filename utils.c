/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:21:06 by smiranda          #+#    #+#             */
/*   Updated: 2024/06/19 17:53:09 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*sl_strdup(char *str)
{
	char	*copy;
	int		i;

	i = 0;
	copy = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

void	free_array(char **array, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(array[j]);
		i++;
	}
	free(array);
}

char	*sl_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	new_str = (char *)malloc(s1_len + s2_len + 1);
	if (!new_str)
		return (NULL);
	sl_strlcpy(new_str, s1, s1_len + 1);
	sl_strlcpy(new_str + (s1_len), s2, s2_len + 1);
	free(s1);
	free(s2);
	return (new_str);
}

size_t	sl_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	while (src[i] != '\0' && (i < dstsize - 1) && dstsize != 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
	{
		if (dst[i - 1] == '\n')
			dst[i - 1] = '\0';
		else
			dst[i] = '\0';
	}
	return (src_len);
}
