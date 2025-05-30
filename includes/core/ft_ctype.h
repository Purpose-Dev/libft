/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 00:54:09 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/05/31 01:09:55 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CTYPE_H
# define FT_CTYPE_H

int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);

int	ft_iscntrl(int c);
int	ft_isgraph(int c);
int	ft_islower(int c);
int	ft_isupper(int c);
int	ft_ispunct(int c);
int	ft_isspace(int c);
int	ft_isxdigit(int c);
int	ft_isblank(int c);

int	ft_toupper(int c);
int	ft_tolower(int c);

# define FT_CTRL_A  0x01
# define FT_CTRL_B  0x02
# define FT_CTRL_C  0x03
# define FT_CTRL_D  0x04
# define FT_CTRL_E  0x05
# define FT_CTRL_F  0x06
# define FT_CTRL_G  0x07
# define FT_CTRL_H  0x08  // Backspace
# define FT_CTRL_I  0x09  // Tab horizontal
# define FT_CTRL_J  0x0A  // Line Feed (newline)
# define FT_CTRL_K  0x0B  // Tab vertical
# define FT_CTRL_L  0x0C  // Form Feed
# define FT_CTRL_M  0x0D  // Carriage Return
# define FT_CTRL_N  0x0E
# define FT_CTRL_O  0x0F
# define FT_CTRL_P  0x10
# define FT_CTRL_Q  0x11
# define FT_CTRL_R  0x12
# define FT_CTRL_S  0x13
# define FT_CTRL_T  0x14
# define FT_CTRL_U  0x15
# define FT_CTRL_V  0x16
# define FT_CTRL_W  0x17
# define FT_CTRL_X  0x18
# define FT_CTRL_Y  0x19
# define FT_CTRL_Z  0x1A
# define FT_ESC     0x1B  // Escape
# define FT_DEL     0x7F  // Delete

# define FT_SPACE   ' '   // 0x20
# define FT_TAB     '\t'  // 0x09
# define FT_NEWLINE '\n'  // 0x0A
# define FT_VTAB    '\v'  // 0x0B
# define FT_FORMFEED '\f' // 0x0C
# define FT_RETURN  '\r'  // 0x0D

#endif // FT_CTYPE_H
