#include "shell.h"

static int32_t ft_typeofpath(const char *bin_path, char **dst)
{
  t_board *board;

  board = ft_get_bin_board();
  while (board)
  {
    write(1, "\e[32m", sizeof("\e[32m"));
    write(1, board->path, ft_strlen(board->path));
    write(1, " :\n\e[37m", sizeof(" :\n\e[37m"));
    while (*board->content)
    {
      write(1, *board->content, ft_strlen(*board->content));
      write(1, "\n", 1);
      board->content++;
    }
    board = board->next;
  }
  return (-1);
}

static void ft_launch_command(const t_cmd * const cmd, const char *bin_path)
{
  pid_t pid;
  extern char **environ;

  pid = fork();
  if (!pid)
  {
    execve(bin_path, cmd->args, environ);
    exit(1);
  }
  else
    wait(NULL);
  // todo : passer a wait pid ** pour utiliser les taches de fonds.
}

void ft_start_command(const t_cmd * const cmd)
{
  int32_t typeof_path;
  char    *bin_path;

  bin_path = NULL;
  typeof_path = ft_typeofpath(*cmd->args, &bin_path);
  if (typeof_path < 0)
  {
    write(1, "\e[31mCommande not found : ", sizeof("\e[31mCommande not found : "));
    write(1, *cmd->args, ft_strlen(*cmd->args));
    write(1, "\e[37m\n", sizeof("\e[37m\n"));
  }
  else if (!typeof_path)
  {
    // builtins maison :-)
  }
  else
    ft_launch_command(cmd, ft_stc_strjoin(bin_path, *cmd->args));
}
