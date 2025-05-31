/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 04:49:12 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/05/31 04:52:09 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/ft_maths.h"

int	ft_mod(const int a, const int b)
{
	int	result;

	if (b == 0)
		return (0);
	result = a % b;
	if (result < 0)
	{
		if (b > 0)
			result += b;
		else
			result -= b;
	}
	return (result);
}
