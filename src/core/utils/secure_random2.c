/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure_random2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 03:15:48 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/11 03:16:26 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/utils/secure_random.h"

float	ft_rand_secure_float(void)
{
	return ((float)(ft_rand_secure_u64() & 0xFFFFFFFFULL) / 4294967295.0f);
}
