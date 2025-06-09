/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 02:57:09 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/09 05:48:30 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/ft_map_utils.h"
#include "core/ctype/ft_ctype.h"

static void	count_digits(const char **str)
{
	while (ft_isdigit((unsigned char)**str))
		(*str)++;
}

static int	comp_same_lgt_nbrs(const char *a, const char *b, const size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (a[i] != b[i])
			return ((unsigned char)a[i] - (unsigned char)b[i]);
		i++;
	}
	return (0);
}

static int	compare_numbers(const char **a, const char **b)
{
	const char	*start_a;
	const char	*start_b;
	size_t		len_a;
	size_t		len_b;

	start_a = *a;
	start_b = *b;
	while (**a == '0' && ft_isdigit((unsigned char)*(*a + 1)))
		(*a)++;
	while (**b == '0' && ft_isdigit((unsigned char)*(*b + 1)))
		(*b)++;
	count_digits(a);
	count_digits(b);
	len_a = (size_t)(*a - start_a);
	len_b = (size_t)(*b - start_b);
	if (len_a != len_b)
	{
		if (len_a > len_b)
			return (1);
		return (-1);
	}
	return (comp_same_lgt_nbrs(start_a, start_b, len_a));
}

static int	compare_numeric_part(const char **a, const char **b)
{
	if (ft_isdigit((unsigned char)**a) && ft_isdigit((unsigned char)**b))
		return (compare_numbers(a, b));
	if (**a != **b)
		return ((unsigned char)**a - (unsigned char)**b);
	(*a)++;
	(*b)++;
	return (0);
}

int	numeric_str_compare(const char *a, const char *b)
{
	int	result;

	if (!a && !b)
		return (0);
	if (!a)
		return (-1);
	if (!b)
		return (1);
	while (*a && *b)
	{
		result = compare_numeric_part(&a, &b);
		if (result != 0)
			return (result);
	}
	return ((unsigned char)*a - (unsigned char)*b);
}
