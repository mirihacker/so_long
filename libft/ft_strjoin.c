/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:42:28 by smiranda          #+#    #+#             */
/*   Updated: 2024/03/19 11:46:04 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*ss;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	ss = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ss || !s1 || !s2)
	{
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		ss[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ss[i + j] = s2[j];
		j++;
	}
	ss[i + j] = '\0';
	return (ss);
}

// #include <stdio.h>

// int main(void)
// {
//     char s1[] = "Smooth ";
//     char s2[] = "like butter";
//     printf("%s",ft_strjoin(s1, s2));
//     return(0);
// }