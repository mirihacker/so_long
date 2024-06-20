/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:05:54 by smiranda          #+#    #+#             */
/*   Updated: 2024/03/18 15:19:16 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	char	*c_ptr;
	size_t	i;

	i = 0;
	ptr = malloc(nmemb * size);
	c_ptr = ptr;
	if (!ptr)
	{
		return (0);
	}
	while (i < nmemb * size)
	{
		c_ptr[i] = 0;
		i++;
	}
	return (ptr);
}

// #include <stdio.h>

// int main(void)
// {
//     size_t nmemb;
//     size_t size;
//     size_t i;
//     char *a;

//     i = 0;
//     nmemb = 10;
//     size = sizeof(char);
//     a = ft_calloc(nmemb, size);
//     if (!a)
//     {
//         printf("Memory allocation failed\n");
//         return(1);
//     }
//     while (i < nmemb)
//     {
//         printf("%d", a[i]);
//         i++;
//     }
//     return(0);
// }