/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 04:00:06 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/02 06:41:43 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RANDOM_H
# define FT_RANDOM_H

// 2^31-1 (Max value for a random on 32-bit systems)
# define FT_RAND_MAX 2147483647L
# define FT_RAND_A 1103515245UL		// Multiplier
# define FT_RAND_C 12345UL			// Increment

extern unsigned long int	g_ft_rand_next;

void	ft_srand(unsigned int seed);
int		ft_rand(void);
double	ft_randf(void);
int		ft_rand_range(int min, int max);

#endif // FT_RANDOM_H
