/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraus <laraus@student.lisboa42.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:42:13 by laraus            #+#    #+#             */
/*   Updated: 2025/11/29 19:10:36 by laraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"
#include <stdlib.h>

static void	free_split(char **split, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	ft_count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
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
	char	*word;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			word = alloc_word(s, c);
			if (!word)
			{
				free_split(split, i);
				return (NULL);
			}
			split[i] = word;
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	return (split);
}

static char	**split_no_delim(char const *s)
{
	char	**split;

	split = malloc(sizeof(char *) * 2);
	if (!split)
		return (NULL);
	split[0] = ft_strdup(s);
	if (!split[0])
	{
		free(split);
		return (NULL);
	}
	split[1] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		words;

	if (!s)
		return (NULL);
	if (c == '\0')
		return (split_no_delim(s));
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
	char	str[] = "\0\0 asbcaicu skvdsohdso";
	char	**split;
	int		i;

	split = ft_split(str, 0);
	if (!split)
		return (1);

	i = 0;
	while (split[i])
	{
		printf("'%s'\n", split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	split = NULL;
	
	return (0);
}
*/