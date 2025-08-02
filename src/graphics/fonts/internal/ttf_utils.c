/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 17:11:08 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/20 21:32:39 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/fonts/ttf_internal.h"

uint16_t	ttf_read_u16_be(const uint8_t *data)
{
	return ((uint16_t)(data[0] << 8) | data[1]);
}

uint32_t	ttf_read_u32_be(const uint8_t *data)
{
	return (((uint32_t)data[0] << 24) | ((uint32_t)data[1] << 16)
		| ((uint32_t)data[2] << 8) | data[3]);
}

int16_t	ttf_read_i16_be(const uint8_t *data)
{
	return ((int16_t)ttf_read_u16_be(data));
}

int32_t	ttf_read_i32_be(const uint8_t *data)
{
	return ((int32_t)ttf_read_u32_be(data));
}

uint64_t	ttf_read_u64_be(const uint8_t *data)
{
	uint64_t	high;
	uint64_t	low;

	high = (uint64_t)ttf_read_u32_be(data);
	low = (uint64_t)ttf_read_u32_be(data + 4);
	return ((high << 32) | low);
}
