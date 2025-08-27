/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncasecmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 02:35:59 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/08/27 02:47:49 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/ctype/ft_ctype.h"
#include "core/strings/ft_strings.h"

static int	ft_compare_chars(const char *s1, const char *s2, const size_t n)
{
	unsigned char	c1;
	unsigned char	c2;
	size_t			i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		c1 = (unsigned char)ft_tolower(s1[i]);
		c2 = (unsigned char)ft_tolower(s2[i]);
		if (c1 != c2)
			return (c1 - c2);
		i++;
	}
	if (i < n)
	{
		c1 = (unsigned char)ft_tolower(s1[i]);
		c2 = (unsigned char)ft_tolower(s2[i]);
		return (c1 - c2);
	}
	return (0);
}

int	ft_strncasecmp(const char *s1, const char *s2, const size_t n)
{
	if (!s1 || !s2)
	{
		if (!s1 && !s2)
			return (0);
		if (s1)
			return (1);
		return (-1);
	}
	if (n == 0)
		return (0);
	return (ft_compare_chars(s1, s2, n));
}
