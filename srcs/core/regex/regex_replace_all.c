/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_replace_all.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 02:17:20 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/14 12:50:17 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/regex/ft_regex.h"
#include "core/string/ft_string.h"

static char	*process_replacement(char *result, const t_regex_match *match,
									const char *replacement)
{
	char	*temp;
	char	*before;
	char	*after;

	temp = result;
	before = ft_substr(result, 0, (size_t)match->start);
	after = ft_strdup(result + match->end);
	result = ft_strjoin_multiple(3, before, replacement, after);
	free(temp);
	free(before);
	free(after);
	free(match->matched_text);
	return (result);
}

char	*regex_replace_all(const char *text, t_regex *regex,
							const char *replacement)
{
	t_regex_match	matches[REGEX_MAX_GROUPS];
	int				match_count;
	char			*result;
	int				i;

	if (!text || !regex || !replacement)
		return (NULL);
	match_count = regex_find_all(regex, text, matches, REGEX_MAX_GROUPS);
	if (match_count == 0)
		return (ft_strdup(text));
	result = ft_strdup(text);
	i = match_count - 1;
	while (i >= 0 && result)
	{
		result = process_replacement(result, &matches[i], replacement);
		i--;
	}
	return (result);
}
