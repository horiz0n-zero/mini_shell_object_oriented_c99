#include "shell.h"

static uint8_t		ft_compare_key(const char *str, const char *ptr)
{
  if (*str == 0)
    return (0);
	while (*ptr)
	{
		if (*str == '=')
			return (0);
		else if (*ptr++ != *str++)
			return (0);
	}
	if (*str != '=')
		return (0);
	else
		return (1);
}

char		*ft_env_for_key(const char *key)
{
	extern char	**environ;
	char		**ptr;

	ptr = environ;
	while (*ptr)
	{
		if (ft_compare_key(*ptr, key))
			return ((*ptr + ft_strlen(key) + 1));
		ptr++;
	}
	return(NULL);
}
