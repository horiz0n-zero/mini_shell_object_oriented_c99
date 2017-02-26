/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 17:07:43 by afeuerst          #+#    #+#             */
/*   Updated: 2017/02/26 17:40:43 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		ft_print_errno__(const int error)
{
	if (error == EINVAL)
		wwrite(2, "Invalid argument\n")
	else if (error == ENFILE)
		wwrite(2, "File table overflow\n")
	else if (error == EMFILE)
		wwrite(2, "Too many open files\n")
	else if (error == ENOTTY)
		wwrite(2, "Not a typewriter\n")
	else if (error == ETXTBSY)
		wwrite(2, "Text file busy\n")
	else if (error == EFBIG)
		wwrite(2, "File too large\n")
	else if (error == ENOSPC)
		wwrite(2, "No space left on device\n")
	else if (error == ESPIPE)
		wwrite(2, "Illegal seek\n")
	else if (error == EROFS)
		wwrite(2, "Read-only file system\n")
	else if (error == EMLINK)
		wwrite(2, "Too many links\n")
	else if (error == EPIPE)
		wwrite(2, "Broken pipe\n")
	else if (error == EDOM)
		wwrite(2, "Math argument out of domain of func\n")
	else
		wwrite(2, "Math result not representable\n")
}

static void		ft_print_errno_(const int error)
{
	if (error == EAGAIN)
		wwrite(2, "Try again\n")
	else if (error == ENOMEM)
		wwrite(2, "Out of memory\n")
	else if (error == EACCES)
		wwrite(2, "Permission denied\n")
	else if (error == EFAULT)
		wwrite(2, "Bad address\n")
	else if (error == ENOTBLK)
		wwrite(2, "Block device required\n")
	else if (error == EBUSY)
		wwrite(2, "Device or resource busy\n")
	else if (error == EEXIST)
		wwrite(2, "File exists\n")
	else if (error == EXDEV)
		wwrite(2, "Cross-device link\n")
	else if (error == ENODEV)
		wwrite(2, "No such device\n")
	else if (error == ENOTDIR)
		wwrite(2, "Not a directory\n")
	else if (error == EISDIR)
		wwrite(2, "Is a directory\n")
	else
		ft_print_errno__(error);
}

static void		ft_print_errno(void)
{
	extern int	errno;

	if (errno == EPERM)
		wwrite(2, "Operation not permitted\n")
	else if (errno == ENOENT)
		wwrite(2, "No such file or directory\n")
	else if (errno == ESRCH)
		wwrite(2, "No such process\n")
	else if (errno == EINTR)
		wwrite(2, "Interrupted system call\n")
	else if (errno == EIO)
		wwrite(2, "I/O error\n")
	else if (errno == ENXIO)
		wwrite(2, "No such device or address\n")
	else if (errno == E2BIG)
		wwrite(2, "Argument list too long\n")
	else if (errno == ENOEXEC)
		wwrite(2, "Exec format error\n")
	else if (errno == EBADF)
		wwrite(2, "Bad file number\n")
	else if (errno == ECHILD)
		wwrite(2, "No child processes\n")
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
