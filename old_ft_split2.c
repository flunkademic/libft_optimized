/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraus <laraus@student.lisboa42.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:42:13 by laraus            #+#    #+#             */
/*   Updated: 2025/11/28 16:46:34 by laraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*alloc_word(char const *s, char c)
{
	int		len;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = ft_substr(s, 0, len);
	return (word);
}

static char	**fill_split(char const *s, char c, char **split)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			split[i] = alloc_word(s, c);
			if (!split[i])
				return (NULL);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		words;

	if (!s)
		return (NULL);
	if (c == '\0')
	{
		split = malloc(2 * sizeof(char *));
		if (!split)
			return (NULL);
		split[0] = ft_strdup(s);
		split[1] = NULL;
		return (split);
	}
	words = ft_count_words(s, c);
	split = ft_calloc(words + 1, sizeof(char *));
	if (!split)
		return (NULL);
	if (!fill_split(s, c, split))
		return (NULL);
	return (split);
}

/*
int	main(void)
{
	char	str[] = " afa sfaf asfasf    asfasfa";
	// char	c = '\0';
	char	**split = NULL;
	split = ft_split(str, 0);
	if (split)
	{	
		for (int i = 0; split[i]; i++)
		{
			printf("'%s'\n", split[i]);
			free(split[i]);
		}
		free(split);
	}
	split = NULL;

	return (0);
}
*/