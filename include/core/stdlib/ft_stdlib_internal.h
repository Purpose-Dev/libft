/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 04:20:29 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/08/27 04:22:21 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_INTERNAL_H
# define FT_STDLIB_INTERNAL_H

int	ft_is_valid_base(int c, int base);
int	ft_char_to_digit(int c, int base);
int	ft_parse_sign(const char **nptr);

#endif // FT_STDLIB_INTERNAL_H
