/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 03:39:20 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/08/27 03:46:44 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <stdlib.h>

int			ft_atoi(const char *nptr);
long		ft_atol(const char *str);
double		ft_atof(const char *str);
long		ft_strtol(const char *nptr, char **endptar, int base);
long		ft_strtoll(const char *nptr, char **endptar, int base);
long		ft_strtoul(const char *nptr, char **endptar, int base);
long		ft_strtoull(const char *nptr, char **endptar, int base);
double		ft_strtod(const char *nptr, char **endptr);
float		ft_strtof(const char *nptr, char **endptr);
long double	ft_strtold(const char *nptr, char **endptr);

#endif // FT_STDLIB_H
