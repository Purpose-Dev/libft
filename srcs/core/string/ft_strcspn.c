/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:46:27 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/03 10:03:34 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/string/ft_string.h"

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t		count;
	const char	*r;

	count = 0;
	while (*s)
	{
		r = reject;
		while (*r)
		{
			if (*s == *r)
				return (count);
			r++;
		}
		s++;
		count++;
	}
	return (count);
}
