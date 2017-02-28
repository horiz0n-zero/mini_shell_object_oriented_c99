
#include "shell.h"

void ft_init_termcaps(void)
{
  char            *current_term;
  struct termios  term;

  current_term = ft_env_for_key("TERM");
  if (current_term == NULL)
  {
    wwrite(1, "impossible d'init les termcaps, term not found\n")
    return ;
  }
  tgetent(NULL, &term);
  //tcgetattr(0, &term);
}
