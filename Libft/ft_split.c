/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarakas <ekarakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 21:56:49 by ekarakas          #+#    #+#             */
/*   Updated: 2026/03/27 19:58:21 by ekarakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static void	free_all(char **res, int j)
{
	while (j > 0)
	{
		j--;
		free(res[j]);
	}
	free(res);
}

static char	*get_word(char const *s, int start, char c)
{
	char	*word;
	int		len;
	int		i;

	len = 0;
	while (s[start + len] && s[start + len] != c)
		len++;
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	fill_split(char const *s, char c, char **res)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			res[j] = get_word(s, i, c);
			if (!res[j])
				return (free_all(res, j), 0);
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	res[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return (NULL);
	if (!fill_split(s, c, res))
		return (NULL);
	return (res);
}

