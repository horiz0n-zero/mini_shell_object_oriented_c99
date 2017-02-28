/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 17:30:51 by afeuerst          #+#    #+#             */
/*   Updated: 2017/02/27 19:47:31 by afeuerst         ###   ########.fr       */
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
		wwrite(1, "Hang-up ")
	else if (signal == SIGALRM)
		wwrite(1, "Alarm ")
	else if (signal == SIGVTALRM)
		wwrite(1, "Virtual time alarm ")
	else if (signal == SIGPROF)
		wwrite(1, "SIGPROF ")
	else if (signal == SIGIO)
		wwrite(1, "SIGIO ")
	else if (signal == SIGURG)
		wwrite(1, "Out of band data ")
	else if (signal == SIGCHLD)
		wwrite(1, "child process terminated ")
	else if (signal == SIGSTOP)
		wwrite(1, "stop process ")
	else if (signal == SIGPIPE)
		wwrite(1, "Broken pipe ")
	else
		wwrite(1, "Unknow signal ")
}

static void			ft_print_signal(const int signal)
{
	if (signal == SIGSEGV)
		wwrite(1, "Segmentation fault ")
	else if (signal == SIGILL)
		wwrite(1, "Illegal instruction ")
	else if (signal == SIGBUS)
		wwrite(1, "Bus error ")
	else if (signal == SIGABRT)
		wwrite(1, "Abort ")
	else if (signal == SIGTRAP)
		wwrite(1, "SIGTRAP ")
	else if (signal == SIGEMT)
		wwrite(1, "Emulator trap ")
	else if (signal == SIGSYS)
		wwrite(1, "Bad system call ")
	else if (signal == SIGTERM)
		wwrite(1, "SIGTERM ")
	else if (signal == SIGINT)
		wwrite(1, "Program interrupt ")
	else if (signal == SIGQUIT)
		wwrite(1, "SIGINT ")
	else
		ft_print_signal_(signal);
}

void			ft_signal(const int signal, const pid_t pid, const char *cmd)
{
	char		*tmp;

	tmp = ft_signal_conv(signal, signal);
	wwrite(1, "\e[33m[");
	write(1, tmp, ft_strlen(tmp));
	write(1, "]    ", 5);
	tmp = ft_signal_conv(pid, pid);
	write(1, tmp, ft_strlen(tmp));
	write(1, " ", 1);
	ft_print_signal(signal);
	write(1, cmd, ft_strlen(cmd));
	wwrite(1, "\e[37m\n")
}
