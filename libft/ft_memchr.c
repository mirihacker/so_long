/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:11:17 by smiranda          #+#    #+#             */
/*   Updated: 2024/03/19 17:19:35 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ss;
	size_t				i;
	unsigned char		cc;

	cc = (unsigned char)c;
	ss = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ss[i] == cc)
			return ((void *)&ss[i]);
		i++;
	}
	return (NULL);
}
// #include <stdio.h>

// int main(void)
// {
//     char s[]= "hermosa para ti?";
//     int c;
//     size_t n;
//     c = 'a';
//     n = 8;
//     printf("%s",ft_memchr(s, c, n));
//     return(0);
// }