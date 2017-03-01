/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 17:30:51 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/01 19:37:42 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char		*ft_signal_conv(int signal, int signal_)
{
	static char	buffer[22];
	char		*ptr;

	ft_memset(buffer, 0, 22);
	ptr = buffer;
	if (signal == 0)
		*ptr = '0';
	while (signal)
	{
		signal /= 10;
		ptr++;
	}
	while (signal_)
	{
		*--ptr = signal_ % 10 + 48;
		signal_ /= 10;
	}
	return (buffer);
}

static void			ft_print_signal_(const int signal)
{
	if (signal == SIGHUP)
		WWRITE(1, "Hang-up ")
	else if (signal == SIGALRM)
		WWRITE(1, "Alarm ")
	else if (signal == SIGVTALRM)
		WWRITE(1, "Virtual time alarm ")
	else if (signal == SIGPROF)
		WWRITE(1, "SIGPROF ")
	else if (signal == SIGIO)
		WWRITE(1, "SIGIO ")
	else if (signal == SIGURG)
		WWRITE(1, "Out of band data ")
	else if (signal == SIGCHLD)
		WWRITE(1, "child process terminated ")
	else if (signal == SIGSTOP)
		WWRITE(1, "stop process ")
	else if (signal == SIGPIPE)
		WWRITE(1, "Broken pipe ")
	else if (signal == SIGFPE)
		WWRITE(1, "Floating point execption ")
	else
		WWRITE(1, "Unknow signal ")
}

static void			ft_print_signal(const int signal)
{
	if (signal == SIGSEGV)
		WWRITE(1, "Segmentation fault ")
	else if (signal == SIGILL)
		WWRITE(1, "Illegal instruction ")
	else if (signal == SIGBUS)
		WWRITE(1, "Bus error ")
	else if (signal == SIGABRT)
		WWRITE(1, "Abort ")
	else if (signal == SIGTRAP)
		WWRITE(1, "SIGTRAP ")
	else if (signal == SIGEMT)
		WWRITE(1, "Emulator trap ")
	else if (signal == SIGSYS)
		WWRITE(1, "Bad system call ")
	else if (signal == SIGTERM)
		WWRITE(1, "SIGTERM ")
	else if (signal == SIGINT)
		WWRITE(1, "Program interrupt ")
	else if (signal == SIGQUIT)
		WWRITE(1, "SIGINT ")
	else
		ft_print_signal_(signal);
}

void			ft_signal(const int signal, const pid_t pid, const char *cmd)
{
	char		*tmp;

	tmp = ft_signal_conv(signal, signal);
	WWRITE(1, "\e[33m[");
	write(1, tmp, ft_strlen(tmp));
	write(1, "]    ", 5);
	tmp = ft_signal_conv(pid, pid);
	write(1, tmp, ft_strlen(tmp));
	write(1, " ", 1);
	ft_print_signal(signal);
	write(1, cmd, ft_strlen(cmd));
	WWRITE(1, "\e[37m\n")
}
