/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 02:42:37 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/09 05:48:22 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/ft_map_utils.h"
#include "core/ctype/ft_ctype.h"
#include "core/memory/ft_memory.h"
#include "core/string/ft_string.h"

int	str_compare(const char *a, const char *b)
{
	if (!a && !b)
		return (0);
	if (!a)
		return (-1);
	if (!b)
		return (1);
	return (ft_strcmp(a, b));
}

int	str_compare_ignorecase(const char *a, const char *b)
{
	int	diff;

	if (!a && !b)
		return (0);
	if (!a)
		return (-1);
	if (!b)
		return (1);
	while (*a && *b)
	{
		diff = ft_tolower((unsigned char)*a) - ft_tolower((unsigned char)*b);
		if (diff != 0)
			return (diff);
		a++;
		b++;
	}
	return (ft_tolower((unsigned char)*a) - ft_tolower((unsigned char)*b));
}

char	*key_duplicate(const char *key)
{
	size_t	len;
	char	*dup;

	if (!key)
		return (NULL);
	len = ft_strlen(key);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, key, len + 1);
	return (dup);
}

void	key_free(char *key)
{
	if (key)
		free(key);
}
