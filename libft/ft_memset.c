/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:28:35 by smiranda          #+#    #+#             */
/*   Updated: 2024/03/18 13:16:08 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, int len)
{
	unsigned char	*p;

	p = b;
	while (len--)
	{
		*p++ = (unsigned char)c;
	}
	return (b);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int c;
// 	int len;

// 	len = 5;

// 	char b[len];
// 	c = 'a';

// 	ft_memset(b, c, len);
// 	printf("%s",b);
// 	return (0);
// }