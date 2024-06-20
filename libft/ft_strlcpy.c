/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:18:16 by smiranda          #+#    #+#             */
/*   Updated: 2024/03/19 16:10:06 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[j] != '\0')
		j++;
	if (dstsize < 1)
		return (j);
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char dst[5];
// 	char *src = "What da fuck?";
// 	size_t dstsize = 5;
// 	printf("%zu\n", ft_strlcpy(dst, src, dstsize));
// 	printf("Copied string: %s\n", dst);
// }