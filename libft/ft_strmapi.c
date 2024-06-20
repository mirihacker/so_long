/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:12:09 by smiranda          #+#    #+#             */
/*   Updated: 2024/03/19 13:01:57 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*r;
	unsigned int	len;
	unsigned int	index;

	index = 0;
	len = ft_strlen(s);
	r = malloc((len + 1) * sizeof(char));
	if (!s || !r)
		return (NULL);
	while (index < len)
	{
		r[index] = (*f)(index, s[index]);
		index++;
	}
	r[index] = '\0';
	return (r);
}

// static char	tupper(unsigned int i, char c)
// {
// 	i = 32;
// 	if (c >= 97 && c <= 122)
// 		c = c - i;
// 	return (c);
// }

// int	main(void)
// {
// 	char (*f)(unsigned int, char);
// 	f = tupper;

// 	char s[] = "Que esta pasanda?";
// 	printf("%s", ft_strmapi(s, f));
// 	return (0);
// }