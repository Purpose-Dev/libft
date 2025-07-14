/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_compile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 02:06:51 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/14 02:15:28 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/regex/ft_regex.h"
#include "core/string/ft_string.h"

static void	init_regex_state(t_regex_state *state, const int id)
{
	state->state_id = id;
	state->is_final = false;
	state->match_char = '\0';
	state->is_any_char = false;
	state->next_state[0] = -1;
	state->next_state[1] = -1;
}

static t_regex	*create_regex(const char *pattern)
{
	t_regex	*regex;

	regex = malloc(sizeof(t_regex));
	if (!regex)
		return (NULL);
	regex->pattern = ft_strdup(pattern);
	if (!regex->pattern)
	{
		free(regex);
		return (NULL);
	}
	regex->states = malloc(sizeof(t_regex_state) * REGEX_MAX_STATES);
	if (!regex->states)
	{
		free(regex->pattern);
		free(regex);
		return (NULL);
	}
	regex->num_states = 0;
	regex->start_state = 0;
	regex->compiled = false;
	return (regex);
}

static bool	compile_simple_pattern(t_regex *regex, const char *pattern)
{
	auto int i = 0;
	auto int state_id = 0;
	while (pattern[i] && state_id < REGEX_MAX_STATES - 1)
	{
		init_regex_state(&regex->states[state_id], state_id);
		if (pattern[i] == '.')
			regex->states[state_id].is_any_char = true;
		else
		{
			regex->states[state_id].match_char = pattern[i];
			regex->states[state_id].is_any_char = false;
		}
		regex->states[state_id].next_state[0] = state_id + 1;
		state_id++;
		i++;
	}
	if (state_id < REGEX_MAX_STATES)
	{
		init_regex_state(&regex->states[state_id], state_id);
		regex->states[state_id].is_final = true;
		regex->num_states = state_id + 1;
		return (true);
	}
	return (false);
}

t_regex	*regex_compile(const char *pattern)
{
	 t_regex	*regex;

	if (!pattern)
		return (NULL);
	regex = create_regex(pattern);
	if (!regex)
		return (NULL);
	if (!compile_simple_pattern(regex, pattern))
	{
		regex_destroy(regex);
		return (NULL);
	}
	regex->compiled = true;
	return (regex);
}
