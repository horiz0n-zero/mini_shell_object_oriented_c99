#include "shell.h"

static void ft_launch_fx(char *path, char *param)
{
  char   *argv[4];
  extern char **environ;
  pid_t     pid;

  pid = fork();
  argv[0] = path;
  argv[1] = path;
  argv[2] = param;
  argv[3] = NULL;
  if (!pid)
  {
      execve("/usr/local/bin/mplayer", argv, environ);
      exit(0);
  }
}

void ft_fx(const enum e_fx fx)
{
  if (fx == click_start)
    ft_launch_fx("./fx/click_start.wav", "-really-quiet");
  else if (fx == click_stop)
    ft_launch_fx("./fx/click_stop.wav", "-really-quiet");
  else if (fx == bip)
   ft_launch_fx("./fx/fx_bip_bomb.wav", "-really-quiet");
  else if (fx == init)
    ft_launch_fx("./fx/init.wav", "-really-quiet");
  else if (fx == long_button)
    ft_launch_fx("./fx/long_button.wav", "-really-quiet");
  else if (fx == short_button)
    ft_launch_fx("./fx/short_button.wav", "-really-quiet");
  else if (fx == stop)
    ft_launch_fx("./fx/stop.wav", "-really-quiet");
  else
    ft_launch_fx("./fx/zzz.wav", "-really-quiet");
}
