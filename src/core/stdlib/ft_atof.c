/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:47:46 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/08/27 04:00:11 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/stdlib/ft_stdlib.h"

double	ft_atof(const char *str)
{
	auto double result = 0;
	auto int sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	if (*str == '.')
	{
		auto double fraction = 0.1;
		str++;
		while (*str >= '0' && *str <= '9')
		{
			result += (*str++ - '0') * fraction;
			fraction *= 0.1;
		}
	}
	return (result * sign);
}
