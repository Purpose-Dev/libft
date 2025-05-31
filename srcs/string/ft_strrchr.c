/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:14:34 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/05/31 17:23:39 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/ft_string.h"

char	*ft_strrchr(const char *s, const int c)
{
	char	*str;
	char	*last;

	if (!s)
		return (NULL);
	str = (char *)s;
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
