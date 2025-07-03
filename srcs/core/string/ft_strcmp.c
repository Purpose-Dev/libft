/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:45:54 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/03 09:59:05 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/string/ft_string.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && s1 == s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 -(unsigned char)*s2);
}
