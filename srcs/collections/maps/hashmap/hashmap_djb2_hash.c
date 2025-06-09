/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_djb2_hash.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 07:59:06 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/09 08:00:34 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/hashmap/ft_hashmap.h"

uint32_t	hashmap_djb2_hash(const char *key)
{
	uint32_t	hash;
	uint32_t	i;

	if (!key)
		return (0);
	hash = 5381;
	i = 0;
	while (key[i])
	{
		hash = ((hash << 5) + hash) + (unsigned char)key[i];
		i++;
	}
	return (hash);
}
