/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_prime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:57:26 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/03 09:10:16 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/maths/ft_maths.h"

int	ft_next_prime(const int n)
{
	int	current_num;

	if (n < 2)
		return (2);
	current_num = n + 1;
	while (current_num > 0)
	{
		if (ft_is_prime(current_num))
			return (current_num);
		if (current_num == INT_MAX)
			break ;
		current_num++;
	}
	return (-1);
}
