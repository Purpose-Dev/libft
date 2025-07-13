/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:55:35 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 21:58:47 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/string_builder/string_builder.h"

void	sb_destroy(t_string_builder *sb)
{
	if (!sb)
		return ;
	free(sb->buffer);
	free(sb);
}

void	sb_clear(t_string_builder *sb)
{
	if (!sb)
		return ;
	sb->buffer[0] = '\0';
	sb->length = 0;
}
