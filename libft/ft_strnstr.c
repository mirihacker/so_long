/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:31:31 by smiranda          #+#    #+#             */
/*   Updated: 2024/03/20 15:59:31 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)(haystack));
	while (haystack[i] != '\0' && (i < len))
	{
		j = 0;
		while (needle[j] && (haystack[i + j] == needle[j]) && ((i + j) < len))
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
// #include <stdio.h>

// int main(void)
// {
//     char haystack[] = "hola cara de bola";
//     char needle[] = "cara de";
//     size_t len = 12;
//     printf("%s",ft_strnstr(haystack, needle, len));
//     return(0);
// }