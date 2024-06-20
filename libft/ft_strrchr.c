/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:01:42 by smiranda          #+#    #+#             */
/*   Updated: 2024/03/20 15:11:45 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*l;

	l = 0;
	while (*s)
	{
		if (*s == (char)c)
		{
			l = s;
		}
		s++;
	}
	if (l != 0)
	{
		return ((char *)l);
	}
	if ((char)c == '\0' && *s == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}
// #include <stdio.h>

// int main(void)
// {
//     char s[] = "Hello lollipop";
//     int c;
//     c = '\0';
//     char *r = ft_strrchr(s, c);
//     if (r == 0)
//     {
//         printf("Character not found\n");
//     }
//     else
//     {
//         printf("Character found at position: %zd\n", r - s);
//     }
//     printf("%s", ft_strrchr(s, c));
//     return(0);
// }