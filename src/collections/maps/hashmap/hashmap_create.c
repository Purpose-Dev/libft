/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 03:06:49 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/09 05:49:29 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/hashmap/ft_hashmap.h"

t_hashmap	*hashmap_create(void)
{
	return (hashmap_create_with_options(HASHMAP_DEFAULT_CAPACITY,
			HASHMAP_DEFAULT_LOAD_FACTOR));
}
