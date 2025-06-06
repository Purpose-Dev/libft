/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:19:19 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/05/31 23:07:00 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/string/ft_string.h"

char	*ft_strnstr(const char *haystack, const char *needle, const size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if ((!haystack && len == 0) || !needle)
		return (0);
	if (needle[0] == '\0')
		return ((char *) haystack);
	while (haystack && haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *) &haystack[i]);
			j++;
		}
		i++;
	}
	return (0);
}
