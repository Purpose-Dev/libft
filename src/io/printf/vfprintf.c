/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vfprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 19:40:20 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/10/26 19:43:37 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io/ft_printf.h"

int	ft_vfprintf(t_ft_file *stream, const char *fmt, va_list ap)
{
	char	*buffer;
	int		len;
	ssize_t	written;

	if (!stream || !fmt)
		return (-1);
	buffer = NULL;
	len = ft_vasprintf(&buffer, fmt, ap);
	if (len < 0 || !buffer)
		return (-1);
	written = ft_fwrite(buffer, 1, len, stream);
	free(buffer);
	if (written < 0)
		return (-1);
	return ((int)written);
}
