/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:55:41 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/01 04:11:39 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/maths/ft_maths.h"

int	ft_is_zero(const double x)
{
	const double	epsilon = 1e-15;

	if (ft_is_nan(x))
		return (0);
	return (ft_fabs(x) < epsilon);
}
