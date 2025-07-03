/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:46:07 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/03 10:01:25 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/string/ft_string.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*h;
	const char	*n;

	if (!needle)
		return ((char *)haystack);
	while (*haystack)
	{
		h = haystack;
		n = needle;
		while (*h && *n && *h == *n)
		{
			h++;
			n++;
		}
		if (!*n)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
