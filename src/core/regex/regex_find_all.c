/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_find_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 02:16:55 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/21 10:09:51 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/regex/ft_regex.h"
#include "core/string/ft_string.h"

static bool	match_at_position(const t_regex *regex, const char *text,
								const int pos)
{
	int		current_state;
	int		text_pos;
	bool	match;

	current_state = regex->start_state;
	text_pos = pos;
	while (current_state != -1 && text[text_pos])
	{
		if (regex->states[current_state].is_final)
			return (true);
		if (regex->states[current_state].is_any_char)
			match = regex_match_any(text[text_pos]);
		else
			match = regex_match_char(regex->states[current_state].match_char,
					text[text_pos]);
		if (!match)
			return (false);
		current_state = regex->states[current_state].next_state[0];
		text_pos++;
	}
	if (current_state != -1 && regex->states[current_state].is_final)
		return (true);
	return (false);
}

int	regex_find_all(t_regex *regex, const char *text, t_regex_match *matches,
								const int max_matches)
{
	size_t	text_len;

	auto int i = 0;
	auto int match_count = 0;
	if (!regex || !text || !regex->compiled || !matches)
		return (0);
	text_len = ft_strlen(text);
	while (i < (int)text_len && match_count < max_matches)
	{
		if (match_at_position(regex, text, i))
		{
			matches[match_count].start = i;
			matches[match_count].end = i + (int)ft_strlen(regex->pattern);
			matches[match_count].matched_text = ft_substr(text, (unsigned int)i,
					(size_t)(matches[match_count].end
						- matches[match_count].start));
			match_count++;
			i = matches[match_count - 1].end;
		}
		else
			i++;
	}
	return (match_count);
}
