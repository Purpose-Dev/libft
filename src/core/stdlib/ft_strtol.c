/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 04:17:37 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/01 08:40:33 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <limits.h>
#include <stdint.h>

#include "core/ctype/ft_ctype.h"
#include "core/stdlib/ft_stdlib.h"
#include "core/stdlib/ft_stdlib_internal.h"

static const char	*ft_skip_whitespace(const char *nptr)
{
	while (ft_isspace((unsigned char)*nptr))
		nptr++;
	return (nptr);
}

static int	ft_detect_base(const char **nptr, const int base)
{
	if (base == 0)
	{
		if (**nptr == '0')
		{
			if (*(*nptr + 1) == 'x' || *(*nptr + 1) == 'X')
			{
				*nptr += 2;
				return (16);
			}
			(*nptr)++;
			return (8);
		}
		return (10);
	}
	if (base == 16)
	{
		if (**nptr == '0' && (*(*nptr + 1) == 'x' || *(*nptr + 1) == 'X'))
			*nptr += 2;
	}
	return (base);
}

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

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	long		result;
	int			sign;
	int			digit;
	const char	*start;
	int			has_digits;

	if (!nptr || base < 0 || base == 1 || base > 36)
	{
		errno = EINVAL;
		if (endptr)
			*endptr = (char *)(intptr_t)nptr;
		return (0);
	}
	result = 0;
	has_digits = 0;
	nptr = ft_skip_whitespace(nptr);
	start = nptr;
	sign = ft_parse_sign(&nptr);
	base = ft_detect_base(&nptr, base);
	while (*nptr)
	{
		digit = ft_char_to_digit(*nptr, base);
		if (digit == -1)
			break ;
		has_digits = 1;
		if (ft_will_overflow(result, digit, sign, base))
		{
			errno = ERANGE;
			if (endptr)
				*endptr = (char *)(intptr_t)nptr;
			if (sign == 1)
				return (LONG_MAX);
			return (LONG_MIN);
		}
		result = result * base + digit;
		nptr++;
	}
	if (!has_digits)
	{
		if (endptr)
			*endptr = (char *)(intptr_t)start;
		return (0);
	}
	if (endptr)
		*endptr = (char *)(intptr_t)nptr;
	return (result * sign);
}
