/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 03:39:20 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/08/28 14:00:20 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# if defined(__x86_64) || defined(_M_X64) || defined(__aarch64__)
#  define FT_ARCH_64BIT 1
# else
#  define FT_ARCH_32BIT 1
# endif // __x86_64 || _M_X64 || __aarch64__

#  if defined(_M_ARM64)
#   define FT_ARCH_64BIT 1
#  endif // _M_ARM64

# ifdef FT_ARCH_64BIT
#  define FT_RAND_MAX 9223372036854775807LL  // 2^63-1 for 64-bit
#  define FT_RAND_A 6364136223846793005ULL   // 64-bit multiplier
#  define FT_RAND_C 1442695040888963407ULL   // 64-bit increment
# else
#  define FT_RAND_MAX 2147483647L            // 2^31-1 for 32-bit
#  define FT_RAND_A 1103515245UL             // 32-bit multiplier
#  define FT_RAND_C 12345UL                 // 32-bit increment
# endif // FT_ARCH_64BIT

extern unsigned long int	g_ft_rand_next;

int			ft_atoi(const char *nptr);
long		ft_atol(const char *str);
double		ft_atof(const char *str);
long		ft_strtol(const char *nptr, char **endptr, int base);
long		ft_strtoll(const char *nptr, char **endptar, int base);
long		ft_strtoul(const char *nptr, char **endptar, int base);
long		ft_strtoull(const char *nptr, char **endptar, int base);
double		ft_strtod(const char *nptr, char **endptr);
float		ft_strtof(const char *nptr, char **endptr);
long double	ft_strtold(const char *nptr, char **endptr);

void		ft_srand(unsigned int seed);
int			ft_rand(void);
double		ft_randf(void);
int			ft_rand_range(int min, int max);

#endif // FT_STDLIB_H
