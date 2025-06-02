/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:56:55 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/02 11:54:37 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/maths/ft_maths.h"

long	ft_fibonacci(const int n)
{
	long	a;
	long	b;
	long	next_fib;
	int		i;

	if (n < 0)
		return (-1L);
	if (n == 0)
		return (0L);
	if (n == 1)
		return (1L);
	a = 0L;
	b = 1L;
	i = 2;
	while (i <= n)
	{
		next_fib = a + b;
		a = b;
		b = next_fib;
		i++;
	}
	return (b);
}
