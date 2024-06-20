/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:16:11 by smiranda          #+#    #+#             */
/*   Updated: 2024/03/18 13:12:57 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *b, size_t len)
{
	unsigned char	*p;

	p = b;
	while (len--)
	{
		*p++ = 0;
	}
}

// #include <stdio.h>

// int  main(void)
// {
//  // Memory area to test
//  char b[] = "Hello, World!";
//  size_t len = sizeof(b); // Length, including but 
//	not including null termination
//  // ft_bzero function call
//  printf("Original string: %s\n", str);
//  ft_bzero(str, n);
//  printf("After ft_bzero: %s\n", str);
//  return (0);
// }