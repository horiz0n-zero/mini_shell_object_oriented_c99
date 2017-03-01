/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 20:17:44 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/01 19:38:18 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char						*ft_ccopy(const char *str)
{
	char						*s;
	char						*ptr;

	if (str == NULL)
		return (NULL);
	s = malloc(ft_strlen(str) + 1);
	ptr = s;
	while (*str)
		*ptr++ = *str++;
	*ptr = 0;
	return (s);
}

void							*ft_ctor(const void * const self, ...)
{
	struct s_cmd				*new;
	va_list						args;
	char						*buffer;

	va_start(args, self);
	buffer = va_arg(args, char*);
	new = malloc(sizeof(struct s_cmd));
	new->class = self;
	new->copy = ft_ccopy(buffer);
	new->args = ft_strsplit(buffer, ft_isspace);
	new->last = va_arg(args, void*);
	new->next = NULL;
	return (new);
}

void							ft_dtor(void * const self)
{
	struct s_cmd				*cmd;

	cmd = (struct s_cmd*)self;
	free(*cmd->args);
	free(cmd->copy);
	free(self);
}
