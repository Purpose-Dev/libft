/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 03:01:44 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/05/31 04:30:44 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATHS_H
# define FT_MATHS_H

# define MIN(a, b) ft_min(a, b)
# define MAX(a, b) ft_max(a, b)

# define MAX(a, b) ({ \
	typeof(a) _a = (a); \
	typeof(b) _b = (b); \
	if (_a > _b) \
		_a; \
	else \
		_b; \
})

int		ft_abs(int n);
long	ft_labs(long n);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
double	ft_pow(double base, int exp);
double	ft_sqrt(double x);

#endif // FT_MATHS_H
