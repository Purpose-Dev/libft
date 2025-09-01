/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:50:35 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/01 08:31:23 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "core/string/ft_string.h"

static size_t	ft_count_digits(const int n)
{
	size_t	count;
	long	nb;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
		count++;
	nb = n;
	if (nb < 0)
		nb = -nb;
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(const int n)
{
	char	*str;
	size_t	len;
	long	nb;

	len = ft_count_digits(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		return (str[0] = '0', str);
	nb = n;
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[--len] = (char)(nb % 10 + '0');
		nb /= 10;
	}
	return (str);
}
