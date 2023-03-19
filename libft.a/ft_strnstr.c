#include <stddef.h>

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	    i;
	int	    temp;
    size_t  j;

	if (*needle == '\0')
		return (haystack);
	while (j < len)
	{
		if (*haystack == *needle)
		{
			i = 0;
			temp = 0;
			while (needle[i] != '\0')
			{
				if (haystack[i] != needle[i])
					temp = 1;
				i++;
			}
			if (temp == 0)
				return (haystack);
		}
		haystack++;
        j++;
	}
	return (0);
}