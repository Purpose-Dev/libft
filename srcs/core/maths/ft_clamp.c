/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:51:29 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/02 06:32:24 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/maths/ft_maths.h"

int	ft_clamp(const int value, const int min, const int max)
{
	if (min <= max)
	{
		if (value < min)
			return (min);
		if (value > max)
			return (max);
		return (value);
	}
	return (max);
}
