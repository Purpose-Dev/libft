/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treemap_contains_key.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 02:59:11 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/13 03:12:03 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps//treemap/ft_treemap.h"

int	treemap_contains_key(t_treemap *map, const char *key)
{
	return (treemap_get(map, key) != NULL);
}
