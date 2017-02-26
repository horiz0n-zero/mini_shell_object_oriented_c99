
# define PRE_UL					(0x01010101)
# define POST_UL				(0x80808080)
# define DETECTNUL(x)			(((x) - PRE_UL) & ~(x) & POST_UL)

# define ALIGNED(p, b)			(!(((uintptr_t)(void const *)p) & (b - 1)))
# define ALIGNEDS(p1, p2, b)	(ALIGNED(p1, b) | ALIGNED(p2, b))

size_t(char const *s)
{
	char const *p;

	p = s;
	while (!ALIGNED(s, sizeof(uint64_t)))
	{
		if (!*s)
			return (s - p);
		++s;
	}
	while (!DETECTNULL(*(uint64_t *)s))
		s += sizeof(uint64_t);
	while (*s)
		++s;
	return (s - p);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*(uint64_t *)s1 == *(uint64_t *)s2)
	{
		if (DETECTNULL(*(uint64_t *)s1))
			return (0);
		s1 += sizeof(uint64_t);
		s2 += sizeof(uint64_t);
	}
	while (*s1 && *(uint8_t *)s1 == *(uint8_t *)s2)
	{
		++s1;
		++s2;
	}
	return (*(uint8_t *)s1 - *(uint8_t *)s2);
}
