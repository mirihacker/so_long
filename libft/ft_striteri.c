/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:43:42 by smiranda          #+#    #+#             */
/*   Updated: 2024/03/19 13:01:00 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	len;
	unsigned int	index;

	index = 0;
	len = ft_strlen(s);
	while (s[index] != '\0')
	{
		(*f)(index, &s[index]);
		index++;
	}
	s[index] = '\0';
}

// static void	tupper(unsigned int i, char *c)
// {
// 	i = 32;
// 	if (*c >= 97 && *c <= 122)
// 		*c = *c - i;
// }
// int	main(void)
// {
// 	void (*f)(unsigned int, char *);
// 	f = tupper;

// 	char s[] = "Que esta pasanda?";
// 	ft_striteri(s, f);
// 	printf("%s", s);
// 	return (0);
// }