/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 01:55:28 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/08/27 02:30:17 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/string/ft_string.h"

const char	*ft_strpbrk(const char *s, const char *accept)
{
	const char	*a;

	if (!s || !accept)
		return (NULL);
	while (*s)
	{
		a = accept;
		while (*a)
		{
			if (*s == *a)
				return (s);
			a++;
		}
		s++;
	}
	return (NULL);
}
