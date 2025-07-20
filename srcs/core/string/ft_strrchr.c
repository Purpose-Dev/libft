/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:14:34 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/18 11:48:07 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/string/ft_string.h"
#include <stdint.h>

char	*ft_strrchr(const char *s, const int c)
{
	char	*str;
	char	*last;

	if (!s)
		return (NULL);
	str = (char *)(intptr_t)s;
	last = NULL;
	while (*str != '\0')
	{
		if (*str == (char)c)
			last = str;
		str++;
	}
	if ((char)c == '\0')
		return (str);
	return (last);
}
