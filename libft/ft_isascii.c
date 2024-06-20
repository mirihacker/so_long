/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:56:47 by smiranda          #+#    #+#             */
/*   Updated: 2024/03/18 13:14:07 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (!(c >= 0 && c <= 127))
	{
		return (0);
	}
	return (1);
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int c = '.';
//     int i = '.';
// 	printf("%i", ft_isascii(c));
// 	if (isascii(i))
// 	{
// 		printf("%s", "true");
// 	}
// 	else
// 	{
// 		printf("%s", "false");
// 	}
// 	return (0);
// }