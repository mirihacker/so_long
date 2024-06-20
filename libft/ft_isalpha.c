/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:36:37 by smiranda          #+#    #+#             */
/*   Updated: 2024/03/18 13:13:48 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
	{
		return (0);
	}
	return (1);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int c;
//     c = 'a';
// 	printf("%i",ft_isalpha(c));
// 	return (0);
// }