/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:11:09 by smiranda          #+#    #+#             */
/*   Updated: 2024/03/20 16:36:04 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(s);
	if (slen - start <= len)
		len = slen - start;
	if (start >= slen)
		return (ft_strdup(""));
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char s[] = "It's Britney bitch";
// 	unsigned int start = 25;
// 	size_t len = 20;
// 	printf("%s", ft_substr(s, start, len));
// 	free(ft_substr(s, start, len));
// 	return (0);
// }