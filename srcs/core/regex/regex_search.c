/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 02:16:44 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/21 10:10:00 by rel-qoqu         ###   ########.fr       */
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

bool	regex_search(t_regex *regex, const char *text, t_regex_match *match)
{
	int		i;
	size_t	text_len;

	if (!regex || !text || !regex->compiled)
		return (false);
	text_len = ft_strlen(text);
	i = 0;
	while (i < (int)text_len)
	{
		if (match_at_position(regex, text, i))
		{
			if (match)
			{
				match->start = i;
				match->end = i + (int)ft_strlen(regex->pattern);
				match->matched_text = ft_substr(text, (unsigned int)i,
						(size_t)match->end - (size_t)match->start);
			}
			return (true);
		}
		i++;
	}
	return (false);
}
