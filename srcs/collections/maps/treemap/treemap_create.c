/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treemap_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 08:20:45 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/11 03:28:12 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps//treemap/ft_treemap.h"

t_treemap	*treemap_create(void)
{
	return (treemap_create_with_comparator(&str_compare));
}
