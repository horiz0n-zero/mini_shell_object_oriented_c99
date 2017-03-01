/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 15:57:08 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/01 19:09:54 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <signal.h>
# include <termios.h>

void				ft_prompt(void);

typedef struct		s_class
{
	size_t			size;
	void			*(*ctor)(const void * const self, ...);
	void			(*dtor)(void * const self);
}					t_class;

typedef struct		s_cmd
{
	const void		*class;
	char			**args;
	char			*copy;
	void			*next;
	void			*last;
}					t_cmd;

void				*ft_ctor(const void *const self, ...);
void				ft_dtor(void *const self);

# define WWRITE(fd, str) write(fd, str, sizeof(str));
# define JOIN(s1, s2) ft_stc_strjoin(s1, s2)
# define OPATH g_info.o_path
# define CHAR_MAX_LINE 1000
# define LEN(x) ft_strlen(x)

void				ft_init_termcaps(void);
void				ft_init_signal(void);
void				ft_signal(const int sig, const pid_t pid, const char *name);

typedef struct		s_info
{
	char			restricted;
	char			*o_path;
	char			*last_pwd;
}					t_info;

extern t_info		g_info;

void				ft_start_command(const t_cmd *const cmd);
int64_t				ft_typeofpath(const char *path, char **ptr, const int i);

typedef struct		s_board
{
	char			*path;
	char			**content;
	struct s_board	*next;
}					t_board;

t_board				*ft_get_bin_board(void);

void				ft_remove_env_for_key(const char *value);
char				*ft_env_for_key(const char *key);
void				ft_save_env(void);
size_t				ft_env_count(void);
void				ft_create_env(void);
char				**ft_strsplit(char *s, int (*f)(int));
int					ft_isspace(const int c);
int					ft_isdoublepoint(const int c);

void				ft_init(void);
uint32_t			ft_builtins(const t_cmd *const cmd);
void				ft_shell(const t_cmd *const cmd);
void				ft_echo(const t_cmd *const cmd);
void				ft_cd(const t_cmd *const cmd);
void				ft_env(const t_cmd *const cmd);
void				ft_unsetenv(const t_cmd *const cmd);
void				ft_setenv(const t_cmd *const cmd);
void				ft_kill(const t_cmd *const cmd);
void				ft_shell_deinit(const t_cmd *cmd);

void				ft_change_key_for_value(const char *key, const char *value);

typedef enum		e_error
{
	global = 0,
}					t_error;
void				ft_error(const enum e_error error);

typedef enum		e_fx
{
	click_start,
	click_stop,
	bip,
	init,
	long_button,
	short_button,
	stop,
	zzz
}					t_fx;
void				ft_fx(const enum e_fx fx);

# define SLASH(x) ft_stc_pluslash(x)
# define SJOIN(x, y) ft_stc_strjoin(x, y)

void				ft_memset_ll(void *const p, const uint64_t v, size_t l);
void				ft_memset(void *const p, const uint8_t v, size_t l);
char				*ft_stc_pluslash(const char *p);
size_t				ft_strlen(const char *str);
char				*ft_stc_strjoin(const char *s1, const char *s2);
char				*ft_copy(const char *copy);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
#endif
