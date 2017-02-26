#include "shell.h"

int ft_isdoublepoint(const int c)
{
  if (c == ':')
    return (1);
  else
    return (0);
}

int ft_isspace(const int c)
{
  if (c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (c == ' ' || c == '\t' || c == '\n');
}
