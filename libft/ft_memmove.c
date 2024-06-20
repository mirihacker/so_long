/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:43:44 by smiranda          #+#    #+#             */
/*   Updated: 2024/03/20 11:43:50 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (s < d && s + len > d)
	{
		i = len;
		while (i-- > 0)
			d[i] = s[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char dst[30];
// 	char src[] = "It's Britney bitch";
// 	size_t len;
// 	size_t i;

// 	i = 0;
// 	len = 10;
// 	ft_memmove(dst, src, len);
// 	while (len > i)
// 	{
// 		printf("%c", dst[i]);
// 		i++;
// 	}
// 	return (0);
// }