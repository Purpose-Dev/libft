/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:00:10 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/05/31 23:04:58 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/memory/ft_memory.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s = src;
	unsigned char		*d;
	size_t				i;

	d = (unsigned char *)dest;
	i = 0;
	if (d == s || n == 0)
		return (dest);
	if (d > s && d < s + n)
	{
		while (n > 0)
		{
			n--;
			d[n] = s[n];
		}
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
