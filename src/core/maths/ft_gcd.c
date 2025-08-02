/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gcd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:48:27 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/02 06:31:30 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/maths/ft_maths.h"

int	ft_gcd(int a, int b)
{
	int	tmp;

	if (a == 0 && b == 0)
		return (0);
	a = ft_abs(a);
	b = ft_abs(b);
	if (a == 0)
		return (b);
	if (b == 0)
		return (a);
	while (b != 0)
	{
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return (a);
}
