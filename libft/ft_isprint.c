/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:48:40 by smiranda          #+#    #+#             */
/*   Updated: 2024/03/18 13:14:41 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (!(c >= 32 && c <= 126))
	{
		return (0);
	}
	return (1);
}
// #include <stdio.h>

// int	main(void)
// {
// 	int c;
// 	c = 127;
// 	printf("%i", ft_isprint(c));
// 	return (0);
// }