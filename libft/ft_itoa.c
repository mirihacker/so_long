/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:37:13 by smiranda          #+#    #+#             */
/*   Updated: 2024/03/19 11:42:36 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_isneg(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

static size_t	ft_intlen(int n)
{
	size_t	len;

	len = 1;
	if (n < 0)
	{
		n = -n;
	}
	while (n >= 10)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*ft_fullma(int n, size_t len, size_t isneg)
{
	char	*s;

	s = malloc(sizeof(char) * (isneg + len + 1));
	if (!s)
		return (NULL);
	s[isneg + len] = '\0';
	if (isneg == 1)
		s[0] = '-';
	while (len > 0)
	{
		len--;
		s[isneg + len] = (n % 10) + '0';
		n = n / 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	len;
	size_t	isneg;
	int		temp;

	temp = n;
	if (n == -2147483648)
		n = -2147483647;
	len = ft_intlen(n);
	isneg = ft_isneg(n);
	if (n < 0)
		n = -n;
	s = ft_fullma(n, len, isneg);
	if (!s)
		return (NULL);
	if (temp == -2147483648)
		s[10] = '8';
	return (s);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int n;
// 	n = 0;
// 	printf("%s", ft_itoa(n));
// 	return (0);
// }