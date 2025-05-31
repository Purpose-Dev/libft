/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:09:25 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/05/31 17:21:26 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/ft_string.h"

char	*ft_strchr(const char *s, const int c)
{
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	while (*str != (char)c && *str != '\0')
		str++;
	if (*str == (char)c)
		return (str);
	return (NULL);
}
