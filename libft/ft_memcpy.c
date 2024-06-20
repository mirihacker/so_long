/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:30:19 by smiranda          #+#    #+#             */
/*   Updated: 2024/03/20 11:42:51 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = dst;
	s = src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (dst != src)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
// #include <stdio.h>

// int main(void)
// {
//     char dst[30];
//     char src[] = "It's Britney bitch";
//     size_t n;
//     n = 12;
//     printf("%s",ft_memcpy(dst, src, n));
//     return(0);
// }