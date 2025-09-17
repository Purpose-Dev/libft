/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:46:56 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/17 19:21:32 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/string/ft_string.h"

static int	is_delimiter(const char c, const char *delim)
{
	while (*delim)
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

char	*ft_strtok(char *str, const char *delim)
{
	static char	*next_token;
	char		*token_start;

	if (str)
		next_token = str;
	if (!next_token)
		return (NULL);
	while (*next_token && is_delimiter(*next_token, delim))
		next_token++;
	if (!*next_token)
		return (NULL);
	token_start = next_token;
	while (*next_token && !is_delimiter(*next_token, delim))
		next_token++;
	if (*next_token)
		*next_token++ = '\0';
	return (token_start);
}

char	*ft_strtok_r(char *str, const char *delim, char **saveptr)
{
	char	*token_start;

	if (str)
		*saveptr = str;
	if (!*saveptr)
		return (NULL);
	while (**saveptr && is_delimiter(**saveptr, delim))
		(*saveptr)++;
	if (!**saveptr)
	{
		*saveptr = NULL;
		return (NULL);
	}
	token_start = *saveptr;
	while (**saveptr && !is_delimiter(**saveptr, delim))
		(*saveptr)++;
	if (**saveptr)
		*(*saveptr)++ = '\0';
	else
		*saveptr = NULL;
	return (token_start);
}
