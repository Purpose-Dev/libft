/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:51:10 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/02 06:32:33 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/maths/ft_maths.h"

long	ft_factorial(const int n)
{
	long	result;
	long	i;

	if (n < 0)
		return (-1);
	if (n == 0)
		return (1);
	result = 1;
	i = 2;
	while (i <= n)
	{
		result *= i;
		i++;
	}
	return (result);
}
