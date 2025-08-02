/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fabs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 03:50:59 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/01 04:06:46 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/maths/ft_maths.h"
#include "core/memory/ft_memory.h"

double	ft_fabs(const double x)
{
	uint64_t	temp_bits;
	double		result;

	ft_memcpy(&temp_bits, &x, sizeof(double));
	temp_bits &= ~(1ULL << 63);
	ft_memcpy(&result, &temp_bits, sizeof(double));
	return (result);
}
