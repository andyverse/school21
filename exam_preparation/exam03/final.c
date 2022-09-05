#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd)
{
	int rd, i = 0;
	char c;
	char *buf = malloc(9999);

	while ((rd = read(fd, &c, 1)) > 0)
	{
		buf[i++] = c;
		if (c == '\n')
			break;
	}
	if ((!buf[i-1] && !rd) || rd == -1)
	{
		free(buf);
		return (NULL);
	}
	buf[i] = '\0';
	return (buf);
}

#include <unistd.h>
#include <stdarg.h>

int g_var = 0;

void ft_putnbr(long dig, int len, char *str)
{
	if (dig >= len)
		ft_putnbr(dig / len, len, str);
	write(1, &str[dig % len], 1);
	g_var++;
}

int ft_printf(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == 's')
			{
				int len = 0;
				char *str = va_arg(ap, char *);
				if (!str)
					str = "(null)";
				while (str[len])
					len++;
				g_var += len;
				write(1, str, len);
			}
			else if (*fmt == 'd')
			{
				int d = va_arg(ap, int);
				if (d < 0)
				{
					g_var++;
					write(1, "-", 1);
					d = -d;
				}
				ft_putnbr(d, 10, "0123456789");
			}
			else if (*fmt == 'x')
			{
				int x = va_arg(ap, unsigned);
				ft_putnbr(x, 16, "0123456789abcdef");
			}
			fmt++;
		}
		else
			g_var += write(1, fmt++, 1);
	}
	va_end(ap);
	return (g_var);
}