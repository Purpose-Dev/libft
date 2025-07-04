/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 00:56:45 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/05/31 01:05:46 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

# ifdef _WIN32
#  include <fcntl.h>
#  include <io.h>
#  ifndef STDIN_FILENO
#   define STDIN_FILENO 0
#  endif
#  ifndef STDOUT_FILENO
#   define STDOUT_FILENO 1
#  endif
#  ifndef STDERR_FILENO
#   define STDERR_FILENO 2
#  endif
# else
#  include <unistd.h>
# endif

# ifdef _WIN32

typedef int	t_ssize;
# endif

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif // FT_IO_H
