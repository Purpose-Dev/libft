/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 03:01:44 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/03 08:43:54 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATHS_H
# define FT_MATHS_H

# include <errno.h>
# include <float.h>
# include <limits.h>
# include <math.h>

typedef union u_double_caster
{
	double				d;
	unsigned long long	ull;
}	t_double_caster;

# define MIN(a, b) ft_min(a, b)
# define MAX(a, b) ft_max(a, b)

# define PI 3.141592653589793
# define EXPONENT_MASK 0x7FF0000000000000ULL // IEEE 754 double-precision
# define MANTISSA_MASK 0x000FFFFFFFFFFFFFULL // IEEE 754 double-precision

int		ft_mod(int a, int b);
double	ft_fmod(double x, double y);
int		ft_abs(int n);
double	ft_fabs(double x);
long	ft_labs(long n);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
double	ft_pow(double base, int exp);
double	ft_sqrt(double x);

int		ft_gcd(int a, int b);
int		ft_lcm(int a, int b);

long	ft_factorial(int n);

int		ft_clamp(int value, int min, int max);
double	ft_clampf(double value, double min, double max);

void	ft_swap(int *a, int *b);
void	ft_swapf(double *a, double *b);

int		ft_sign(int n);
int		ft_signf(double n);

double	ft_floor(double x);
double	ft_ceil(double x);
double	ft_round(double x);

double	ft_trunc(double x);

double	ft_deg_to_rad(double degrees);
double	ft_rad_to_deg(double radians);

double	ft_sin(double x);
double	ft_cos(double x);
double	ft_tan(double x);

double	ft_sinh(double x);
double	ft_cosh(double x);

int		ft_double_equals(double a, double b, double epsilon);
int		ft_is_zero(double x);
int		ft_is_nan(double x);
int		ft_is_inf(double x);

long	ft_fibonacci(int n);
int		ft_is_prime(int n);
int		ft_next_prime(int n);

#endif // FT_MATHS_H
