/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gen_val.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 03:37:10 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/12 03:40:24 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/vectors/vector.h"

t_value	ft_gen_val(const t_type type, const t_any value)
{
	return ((t_value){
		.type = type,
		.value = value,
	});
}
