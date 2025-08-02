/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:57:14 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/02 06:50:37 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/maths/ft_maths.h"

int	ft_is_prime(const int n)
{
	int	i;
	int	limit;

	if (n <= 1)
		return (0);
	if (n == 2)
		return (1);
	if (n % 2 == 0)
		return (0);
	limit = (int)ft_sqrt(n);
	i = 3;
	while (i <= limit)
	{
		if (n % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}
