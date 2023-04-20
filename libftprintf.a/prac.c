#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	while (*(s))
	{
		write(fd, s, 1);
		s++;
	}
}

void	printValues(char *types, ...)
{
	va_list ap;
	int		i;
	
	va_start(ap, types);
	while (*types != '\0')
	{
		switch (*types)
		{
			// case 'i':
			// 	printf("%d ", va_arg(ap, int));
			// 	break ;
			// case 'd':
			// 	printf("%f ", va_arg(ap, double));
			// 	break ;
			// case 'c':
			// 	printf("%c ", va_arg(ap, int));
			// 	break ;
			// case 's':
			// 	printf("%s ", va_arg(ap, char *));
			// 	break ;
			// case 'p':
			// 	printf("%p ", va_arg(ap, char *));
			// 	break ;
			// default:
			// 	break ;
			case 's':
				ft_putstr_fd(va_arg(ap, char *), 1);
				break ;
			case 'p':
				write(1, "0x", 2);
				ft_get_hex((unsigned long long)va_arg(ap, char *));
				break ;
			default:
				break ;
		}
		types++;
	}
	va_end(ap);
	printf("\n");
}

int main()
{
	char *pp;

	// printValues("i", 10);
	// printValues("ci", 'a', 10);
	// printValues("dci", 1.234567, 'a', 10);
	// printValues("sicd", "Hello, world!", 10, 'a', 1.234567);
	printValues("psicd", pp, "Hello, world!", 10, 'a', 1.234567);
	printf("\n%p", pp);
}