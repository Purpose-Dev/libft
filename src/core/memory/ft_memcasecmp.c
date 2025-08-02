/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:34:42 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/07 01:44:41 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/ctype/ft_ctype.h"
#include "core/memory/ft_memory.h"

int	ft_memcasecmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1 = s1;
	const unsigned char	*p2 = s2;
	unsigned char		lw1;
	unsigned char		lw2;
	size_t				i;

	i = 0;
	while (i < n)
	{
		lw1 = (unsigned char)ft_tolower(p1[i]);
		lw2 = (unsigned char)ft_tolower(p2[i]);
		if (lw1 != lw2)
			return (lw1 - lw2);
		i++;
	}
	return (0);
}
