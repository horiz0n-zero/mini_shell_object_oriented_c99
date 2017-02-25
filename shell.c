/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 16:00:37 by afeuerst          #+#    #+#             */
/*   Updated: 2017/02/25 23:32:29 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static const struct s_class	g_desc_cmd =
{
	sizeof(struct s_cmd), ft_ctor, ft_dtor
};

static const void * const	g_ptr_cmd = &g_desc_cmd;

static void					ft_launch_command(const char *buffer, t_cmd **cmds)
{
	if (*cmds == NULL)
		*cmds = (*(t_class*)g_ptr_cmd).ctor(g_ptr_cmd, buffer, NULL);
	else
		*cmds = (*(t_class*)g_ptr_cmd).ctor(g_ptr_cmd, buffer, *cmds);
}

int							main(void)
{
	char					buffer[5000];
	char					*ptr;
	int						ret;
	struct s_cmd			*cmds;

	cmds = NULL;
	ret = 0;
	ptr = buffer;
	ft_memset(buffer, 0, 5000);
	clear
	while (1 | (ret = read(1, ptr, 1)))
	{
		if (ret)
		{
			if (*ptr == '\n')
			{
				if (ptr != buffer)
					ft_launch_command(buffer, &cmds);
				enter_mode
				ptr = buffer;
				ft_memset(buffer, 0, 5000);
			}
			else
				ptr++;
		}
	}
}
