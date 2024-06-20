/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:50:18 by smiranda          #+#    #+#             */
/*   Updated: 2024/03/20 12:38:34 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if ((char)c == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}
// #include <stdio.h>

// int main(void)
// {
//     char s[] = "It's Britney bitch";
//     int c;
//     c = 'i' + 256;
//     char *r = ft_strchr(s, c);
//     if (r == NULL)
//     {
//         printf("Character not found\n");
//     }
//     else
//     {
//         printf("Character found at position: %zd\n", r - s);
//     }
// 	printf("%s", ft_strchr(s, c));
//     return(0);
// }