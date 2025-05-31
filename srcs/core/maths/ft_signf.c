/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:52:10 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/05/31 18:37:25 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/ft_maths.h"

int	ft_signf(const double n)
{
	if (ft_is_nan(n))
		return (0);
	if (ft_is_inf(n))
	{
		if (n > 0.0)
			return (1);
		return (-1);
	}
	if (n < 0.0)
		return (-1);
	else if (n > 0.0)
		return (1);
	return (0);
}
