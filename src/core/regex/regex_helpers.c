/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 01:53:03 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/14 02:02:08 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/regex/ft_regex.h"

bool	regex_match_char(const char pattern_char, const char text_char)
{
	return (pattern_char == text_char);
}

bool	regex_match_any(const char text_char)
{
	return (text_char != '\0');
}

static bool	check_range_match(const char *range, const char text_char,
								const int i)
{
	if (range[i + 1] == '-' && range[i + 2] && range[i + 2] == ']')
	{
		if (text_char >= range[i] && text_char <= range[i + 2])
			return (true);
	}
	else
	{
		if (range[i] == text_char)
			return (true);
	}
	return (false);
}

bool	regex_match_range(const char *range, const char text_char)
{
	auto int i = 0;
	auto bool negate = false;
	auto bool match = false;
	if (!range || !*range)
		return (false);
	if (range[0] == '^')
	{
		negate = true;
		i = 1;
	}
	while (range[i] && range[i] != ']')
	{
		if (check_range_match(range, text_char, i))
			match = true;
		if (range[i + 1] == '-' && range[i + 2] && range[i + 2] != ']')
			i += 3;
		else
			i++;
	}
	if (negate)
		return (!match);
	return (match);
}
