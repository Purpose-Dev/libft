/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 06:51:44 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/08/24 06:52:57 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/memory/ft_memory.h"
#include "core/string/ft_string.h"

char	*ft_strndup(const char *str, const size_t n)
{
	char	*copy;
	size_t	len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (n < len)
		len = n;
	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	ft_memcpy(copy, str, len);
	copy[len] = '\0';
	return (copy);
}
