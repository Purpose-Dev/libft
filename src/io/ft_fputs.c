/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:01:56 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/11/05 10:01:31 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/string/ft_string.h"
#include "io/ft_io.h"

int	ft_fputs(const char *s, t_ft_file *stream)
{
	size_t	len;
	size_t	i;

	if (!s || !stream)
		return (FT_EOF);
	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		if (ft_fputc(s[i], stream) == FT_EOF)
			return (FT_EOF);
		i++;
	}
	return ((int32_t)i);
}
