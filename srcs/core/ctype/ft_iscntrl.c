/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscntrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 03:41:13 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/05/31 22:57:21 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/ctype/ft_ctype.h"

int	ft_iscntrl(const int c)
{
	return ((c >= 0 && c <= 31) || c == 127);
}
