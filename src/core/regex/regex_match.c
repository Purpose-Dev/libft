/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_match.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 02:16:22 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/21 10:09:44 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/regex/ft_regex.h"

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

bool	regex_match(t_regex *regex, const char *text)
{
	if (!regex || !text || !regex->compiled)
		return (false);
	return (match_at_position(regex, text, 0));
}
