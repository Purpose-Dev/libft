/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:19:19 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/20 13:45:05 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/string/ft_string.h"
#include <stdint.h>

char	*ft_strnstr(const char *haystack, const char *needle, const size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if ((!haystack && len == 0) || !needle)
		return (0);
	if (needle[0] == '\0')
		return ((char *)(intptr_t)haystack);
	while (haystack && haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)(intptr_t) & haystack[i]);
			j++;
		}
		i++;
	}
	return (0);
}
