/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_replace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 02:17:16 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/14 12:43:42 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/regex/ft_regex.h"
#include "core/string/ft_string.h"

char	*regex_replace(const char *text, t_regex *regex,
						const char *replacement)
{
	t_regex_match	match;
	char			*result;
	char			*before;
	char			*after;

	if (!text || !regex || !replacement)
		return (NULL);
	if (!regex_search(regex, text, &match))
		return (ft_strdup(text));
	before = ft_substr(text, 0, (size_t)match.start);
	after = ft_strdup(text + match.end);
	if (!before || !after)
	{
		free(before);
		free(after);
		free(match.matched_text);
		return (NULL);
	}
	result = ft_strjoin_multiple(3, before, replacement, after);
	free(before);
	free(after);
	free(match.matched_text);
	return (result);
}
