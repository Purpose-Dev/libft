/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:46:39 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/03 10:06:31 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/string/ft_string.h"

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t		count;
	const char	*a;
	int			found;

	count = 0;
	while (*s)
	{
		a = accept;
		found = 0;
		while (*a)
		{
			if (*s == *a)
			{
				found = 1;
				break ;
			}
			a++;
		}
		if (!found)
			return (count);
		s++;
		count++;
	}
	return (count);
}
