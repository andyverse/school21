#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	g_var = 0;

void	ft_putnbr(long dig, int len, char *sign)
{
	if (dig >= len)
		ft_putnbr(dig / len, len, sign);
	write(1, &sign[dig % len], 1);
	g_var++;
}

int	ft_printf(const char *fmt, ...)
{
	long			d;
	unsigned int	x;
	int				len;
	char			*str;

	va_list ap;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == 's')
			{
				len = 0;
				str = va_arg(ap, char *);
				if (!str)
					str = "(null)";
				while (str[len])
					len++;
				write(1, str, len);
				g_var += len;
			}
			else if (*fmt == 'd')
			{
				d = va_arg(ap, int);
				if (d < 0)
				{
					d = -d;
					write(1, "-", 1);
					g_var++;
				}
				ft_putnbr(d, 10, "0123456789");
			}
			else if (*fmt == 'x')
			{
				x = va_arg(ap, unsigned);
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

int main(void)
{
	int res;
	int ret;

	res = ft_printf("%d\n", 2147483649);
	ret = printf("%d\n", 2147483649);
	printf("%d %d", res, ret);
}