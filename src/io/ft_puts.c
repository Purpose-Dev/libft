/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:01:43 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/10/26 20:18:20 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io/ft_io.h"

int	ft_puts(const char *s)
{
	if (ft_fputs(s, ft_stdout()) == FT_EOF)
		return (FT_EOF);
	if (ft_fputc('\n', ft_stdout()) == FT_EOF)
		return (FT_EOF);
	return (ft_fflush(ft_stdout()));
}
