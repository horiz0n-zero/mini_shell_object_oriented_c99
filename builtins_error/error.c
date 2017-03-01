/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 17:07:43 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/01 19:33:45 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		ft_print_errno__(const int error)
{
	if (error == EINVAL)
		WWRITE(2, "Invalid argument\n")
	else if (error == ENFILE)
		WWRITE(2, "File table overflow\n")
	else if (error == EMFILE)
		WWRITE(2, "Too many open files\n")
	else if (error == ENOTTY)
		WWRITE(2, "Not a typewriter\n")
	else if (error == ETXTBSY)
		WWRITE(2, "Text file busy\n")
	else if (error == EFBIG)
		WWRITE(2, "File too large\n")
	else if (error == ENOSPC)
		WWRITE(2, "No space left on device\n")
	else if (error == ESPIPE)
		WWRITE(2, "Illegal seek\n")
	else if (error == EROFS)
		WWRITE(2, "Read-only file system\n")
	else if (error == EMLINK)
		WWRITE(2, "Too many links\n")
	else if (error == EPIPE)
		WWRITE(2, "Broken pipe\n")
	else if (error == EDOM)
		WWRITE(2, "Math argument out of domain of func\n")
	else
		WWRITE(2, "Math result not representable\n")
}

static void		ft_print_errno_(const int error)
{
	if (error == EAGAIN)
		WWRITE(2, "Try again\n")
	else if (error == ENOMEM)
		WWRITE(2, "Out of memory\n")
	else if (error == EACCES)
		WWRITE(2, "Permission denied\n")
	else if (error == EFAULT)
		WWRITE(2, "Bad address\n")
	else if (error == ENOTBLK)
		WWRITE(2, "Block device required\n")
	else if (error == EBUSY)
		WWRITE(2, "Device or resource busy\n")
	else if (error == EEXIST)
		WWRITE(2, "File exists\n")
	else if (error == EXDEV)
		WWRITE(2, "Cross-device link\n")
	else if (error == ENODEV)
		WWRITE(2, "No such device\n")
	else if (error == ENOTDIR)
		WWRITE(2, "Not a directory\n")
	else if (error == EISDIR)
		WWRITE(2, "Is a directory\n")
	else
		ft_print_errno__(error);
}

static void		ft_print_errno(void)
{
	extern int	errno;

	if (errno == EPERM)
		WWRITE(2, "Operation not permitted\n")
	else if (errno == ENOENT)
		WWRITE(2, "No such file or directory\n")
	else if (errno == ESRCH)
		WWRITE(2, "No such process\n")
	else if (errno == EINTR)
		WWRITE(2, "Interrupted system call\n")
	else if (errno == EIO)
		WWRITE(2, "I/O error\n")
	else if (errno == ENXIO)
		WWRITE(2, "No such device or address\n")
	else if (errno == E2BIG)
		WWRITE(2, "Argument list too long\n")
	else if (errno == ENOEXEC)
		WWRITE(2, "Exec format error\n")
	else if (errno == EBADF)
		WWRITE(2, "Bad file number\n")
	else if (errno == ECHILD)
		WWRITE(2, "No child processes\n")
	else
		ft_print_errno_(errno);
}

void			ft_error(const enum e_error error)
{
	if (error == global)
	{
		ft_print_errno();
		return ;
	}
}
