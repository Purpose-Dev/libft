/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strerror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 02:12:09 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/11 20:50:48 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/string/ft_string.h"
#include "io/ft_printf.h"

static const char	*get_error_message(const int errnum)
{
	static const char	*error_messages[] = {
		"Success", "Operation not permitted", "No such file or directory",
		"No such process", "Interrupted system call", "Input/output error",
		"No such device or address", "Argument list too long",
		"Exec format error", "Bad file descriptor", "No child processes",
		"Resource temporarily unavailable", "Cannot allocate memory",
		"Permission denied", "Bad address", "Block device required",
		"Device or resource busy", "File exists", "Invalid cross-device link",
		"No such device", "Not a directory", "Is a directory",
		"Invalid argument", "Too many open files in system",
		"Too many open files", "Inappropriate ioctl for device",
		"Text file busy", "File too large", "No space left on device",
		"Illegal seek", "Read-only file system", "Too many links",
		"Broken pipe", "Numerical argument out of domain",
		"Numerical result out of range"
	};

	if (errnum >= 0 && errnum < 35)
		return (error_messages[errnum]);
	return ("Unknown error");
}

const char	*ft_strerror(const int errnum)
{
	static char	unknown_buffer[64];
	const char	*msg;

	msg = get_error_message(errnum);
	if (ft_strcmp(msg, "Unknown error") == 0)
	{
		ft_snprintf(unknown_buffer, 64, "Unknown error %d", errnum);
		return (unknown_buffer);
	}
	return (msg);
}
