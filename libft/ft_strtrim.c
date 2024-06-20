/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:55:07 by smiranda          #+#    #+#             */
/*   Updated: 2024/03/18 13:18:36 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*t;
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	if (!s1 || !set)
	{
		return (NULL);
	}
	while (s1[start] && ft_strchr(set, s1[start]))
	{
		start++;
	}
	while (end > start && ft_strchr(set, s1[end - 1]))
	{
		end--;
	}
	t = malloc((end - start + 1) * sizeof(char));
	if (!t)
		return (NULL);
	ft_strlcpy(t, s1 + start, end - start + 1);
	return (t);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char s1[] = "Smooth like butter";
// 	char set[] = "rS";
// 	printf("%s", ft_strtrim(s1, set));
// 	return (0);
// }