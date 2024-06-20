/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:45:06 by smiranda          #+#    #+#             */
/*   Updated: 2024/03/20 15:29:05 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	slen;
	size_t	dlen;

	i = 0;
	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	j = dlen;
	if (!dst && dstsize == 0)
		return (slen);
	if (dstsize <= j)
		return (dstsize + slen);
	while (src[i] && j + 1 < dstsize)
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (slen + dlen);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	dst[30] = "It's Britney";
// 	char	*src;
// 	size_t	dstsize;

// 	src = " bitch";
// 	dstsize = 30;
// 	printf("%zu\n", ft_strlcat(dst, src, dstsize));
// 	printf("Copied string: %s\n", dst);
// 	return (0);
// }
