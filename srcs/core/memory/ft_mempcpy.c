/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mempcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:41:42 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/21 10:29:40 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/memory/ft_memory.h"

void	*ft_mempcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*src_ = src;
	unsigned char		*dst_;

	dst_ = (unsigned char *)dst;
	while (n--)
		*dst_++ = *src_++;
	return (dst_);
}
