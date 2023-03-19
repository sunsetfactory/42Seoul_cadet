char * ft_strchr(const char *s, int c)
{
    while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	return (0);
}