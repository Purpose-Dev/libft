/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:09:25 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/18 11:48:34 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/string/ft_string.h"
#include <stdint.h>

char	*ft_strchr(const char *s, const int c)
{
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)(intptr_t)s;
	while (*str != (char)c && *str != '\0')
		str++;
	if (*str == (char)c)
		return (str);
	return (NULL);
}
