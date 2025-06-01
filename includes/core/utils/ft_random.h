/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 04:00:06 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/01 04:02:22 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RANDOM_H
# define FT_RANDOM_H

# define FT_RAND_MAX 2147483647L // 2^31 - 1

void	ft_srand(unsigned int seed);
int		ft_rand(void);
double	ft_randf(void);
int		ft_rand_range(int min, int max);

#endif // FT_RANDOM_H
