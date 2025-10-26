/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atexit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 21:32:24 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/10/26 21:39:14 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/stdlib/ft_stdlib.h"

#define MAX_ATEXIT_FUNCS 32

static void	((*g_atexit_funcs[MAX_ATEXIT_FUNCS])(void));
static int	g_atexit_count = 0;

__attribute__((destructor))
static void	ft_atexit_handler(void)
{
	int	i;

	i = g_atexit_count - 1;
	while (i >= 0)
	{
		if (g_atexit_funcs[i])
			g_atexit_funcs[i]();
		i--;
	}
}

int	ft_atexit(void (*func)(void))
{
	if (!func || g_atexit_count >= MAX_ATEXIT_FUNCS)
		return (-1);
	g_atexit_funcs[g_atexit_count++] = func;
	return (0);
}
