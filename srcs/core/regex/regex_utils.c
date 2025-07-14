/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 02:17:10 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/14 02:50:14 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/regex/ft_regex.h"

bool	regex_is_valid_pattern(const char *pattern)
{
	auto int i = 0;
	auto int bracket_count = 0;
	auto int paren_count = 0;
	if (!pattern)
		return (false);
	while (pattern[i])
	{
		if (pattern[i] == '[')
			bracket_count++;
		else if (pattern[i] == ']')
			bracket_count--;
		else if (pattern[i] == '(')
			paren_count++;
		else if (pattern[i] == ')')
			paren_count--;
		if (bracket_count < 0 || paren_count < 0)
			return (false);
		i++;
	}
	if (bracket_count == 0 && paren_count == 0)
		return (true);
	return (false);
}
