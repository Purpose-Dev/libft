/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 04:17:37 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/17 19:17:36 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <limits.h>
#include <stdint.h>

#include "core/stdlib/ft_stdlib.h"
#include "core/stdlib/ft_stdlib_internal.h"

static int	ft_will_overflow(const long result, const int digit,
				const int sign, const int base)
{
	long	limit;
	long	limit_digit;

	if (sign == 1)
	{
		limit = LONG_MAX / base;
		limit_digit = LONG_MAX % base;
		return (result > limit || (result == limit && digit > limit_digit));
	}
	limit = -(LONG_MIN / base);
	limit_digit = -(LONG_MIN % base);
	return (result > limit || (result == limit && digit > limit_digit));
}

static long	ft_return_overflow(const char *nptr, char **endptr, const int sign)
{
	if (endptr)
		*endptr = (char *)(intptr_t)nptr;
	if (sign == 1)
		return (LONG_MAX);
	return (LONG_MIN);
}

static int	ft_process_digit(const char **nptr, long *result, const int base,
				const int sign)
{
	int	digit;

	digit = ft_char_to_digit(**nptr, base);
	if (digit == -1)
		return (0);
	if (ft_will_overflow(*result, digit, sign, base))
	{
		errno = ERANGE;
		return (-1);
	}
	*result = *result * base + digit;
	(*nptr)++;
	return (1);
}

static long	ft_parse_digits(const char *nptr, char **endptr, const int base,
				const int sign)
{
	long		result;
	int			has_digits;
	const char	*start;
	int			status;

	result = 0;
	has_digits = 0;
	start = nptr;
	while (*nptr != '\0')
	{
		status = ft_process_digit(&nptr, &result, base, sign);
		if (status == 0)
			break ;
		if (status == -1)
			return (ft_return_overflow(nptr, endptr, sign));
		has_digits = 1;
	}
	if (!has_digits && endptr)
		*endptr = (char *)(intptr_t)start;
	else if (endptr)
		*endptr = (char *)(intptr_t)nptr;
	return (result * sign);
}

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	int	sign;

	if (!nptr || base < 0 || base == 1 || base > 36)
	{
		errno = EINVAL;
		if (endptr)
			*endptr = (char *)(intptr_t)nptr;
		return (0);
	}
	nptr = ft_skip_whitespace(nptr);
	sign = ft_parse_sign(&nptr);
	base = ft_detect_base(&nptr, base);
	return (ft_parse_digits(nptr, endptr, base, sign));
}
