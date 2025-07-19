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

# include <stdio.h>
# include <stdlib.h>

# ifdef _WIN32
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

# define FT_EOF (-1)
# define FT_BUFSIZ 8192

typedef int	t_ssize;
# endif
t_ft_file	*ft_stdin(void);
t_ft_file	*ft_stdout(void);
t_ft_file	*ft_stderr(void);

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

#endif // FT_IO_H
