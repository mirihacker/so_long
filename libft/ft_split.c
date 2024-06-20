/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:19:57 by smiranda          #+#    #+#             */
/*   Updated: 2024/03/20 13:50:43 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_array(char **wordlist, size_t wrdnbr)
{
	while (wrdnbr > 0)
	{
		--wrdnbr;
		free(wordlist[wrdnbr]);
	}
	free(wordlist);
	return (NULL);
}

static size_t	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	wrdnbr;

	i = 0;
	wrdnbr = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		wrdnbr++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (wrdnbr);
}

static int	ft_word(char **wordlist, char const *s, char c, size_t *word)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		len++;
		i++;
	}
	wordlist[*word] = malloc(sizeof(char) * (len + 1));
	if (!wordlist[*word])
	{
		free_array(wordlist, *word);
		return (0);
	}
	if (wordlist[*word])
	{
		ft_strlcpy(wordlist[*word], s, len + 1);
		(*word)++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**wordlist;
	size_t	wrdnbr;
	size_t	word;
	size_t	i;

	wrdnbr = ft_count(s, c);
	word = 0;
	i = 0;
	if (!s)
		return (NULL);
	wordlist = malloc(sizeof(char *) * (wrdnbr + 1));
	if (!wordlist)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
			if (!ft_word(wordlist, &s[i], c, &word))
				return (NULL);
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			i++;
	}
	wordlist[word] = NULL;
	return (wordlist);
}

// int	main(void)
// {
// 	char	s[] = "      split       this for   me  !       ";
// 	char	c;
// 	char	**s2;
// 	int		i;

// 	c = ' ';
// 	i = 0;
// 	s2 = ft_split(s, c);
// 	while (s2[i] != NULL)
// 	{
// 		printf("%s\n", s2[i]);
// 		i++;
// 	}
// 	return (0);
// }
