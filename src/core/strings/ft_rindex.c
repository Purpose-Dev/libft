/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rindex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 02:36:13 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/08/27 02:49:00 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/strings/ft_strings.h"

const char	*ft_rindex(const char *s, const int c)
{
	const char	*last;
	char		ch;

	if (!s)
		return (NULL);
	ch = (char)c;
	last = NULL;
	while (*s)
	{
		if (*s == ch)
			last = s;
		s++;
	}
	if (ch == '\0')
		return (s);
	return (last);
}
