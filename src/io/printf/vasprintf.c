/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vasprintf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 19:49:24 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/10/26 19:52:18 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io/ft_printf.h"

int	ft_vasprintf(char **strp, const char *fmt, va_list ap)
{
	va_list	ap_copy;
	int		len;
	char	*buffer;

	if (!strp || !fmt)
		return (-1);
	va_copy(ap_copy, ap);
	len = ft_vsnprintf(NULL, 0, fmt, ap_copy);
	va_end(ap_copy);
	if (len < 0)
		return (-1);
	buffer = (char *)malloc((size_t)len +1);
	if (!buffer)
		return (-1);
	len = ft_vsnprintf(buffer, (size_t)len + 1, fmt, ap);
	if (len < 0)
	{
		free(buffer);
		return (1);
	}
	*strp = buffer;
	return (len);
}
