/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure_random.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 01:48:24 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/11 03:08:36 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SECURE_RANDOM_H
# define SECURE_RANDOM_H

# include <stddef.h>
# include <stdint.h>

# define FT_RANDOM_SUCCESS 0
# define FT_RANDOM_FAIL    -1

void		ft_srand_secure(uint64_t seed);
uint32_t	ft_rand_secure_u32(void);
uint64_t	ft_rand_secure_u64(void);
int			ft_rand_secure_range(int min, int max);
float		ft_rand_secure_float(void);

#endif // SECURE_RANDOM_H
