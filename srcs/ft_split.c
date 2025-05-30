/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:50:29 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/05/12 23:36:07 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*ft_extract_word(char const *s, char c, size_t *pos)
{
	size_t	word_len;
	size_t	i;
	char	*word;

	word_len = 0;
	while (s[*pos + word_len] && s[*pos + word_len] != c)
		word_len++;
	word = (char *)malloc(sizeof(char) * (word_len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < word_len)
	{
		word[i] = s[*pos + i];
		i++;
	}
	word[i] = '\0';
	*pos += word_len;
	return (word);
}

static void	ft_free_split(char **split, size_t word_count)
{
	size_t	i;

	i = 0;
	while (i < word_count)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	word_count;
	size_t	i;
	size_t	pos;

	if (!s)
		return (NULL);
	word_count = ft_count_words(s, c);
	split = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!split)
		return (NULL);
	i = 0;
	pos = 0;
	while (i < word_count)
	{
		while (s[pos] && s[pos] == c)
			pos++;
		split[i] = ft_extract_word(s, c, &pos);
		if (!split[i])
			return (ft_free_split(split, i), NULL);
		i++;
	}
	split[word_count] = NULL;
	return (split);
}
