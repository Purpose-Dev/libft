/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 02:07:09 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/14 02:08:06 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/regex/ft_regex.h"

void	regex_destroy(t_regex *regex)
{
	if (!regex)
		return ;
	if (regex->pattern)
		free(regex->pattern);
	if (regex->states)
		free(regex->states);
	free(regex);
}
