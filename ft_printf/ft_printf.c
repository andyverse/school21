#include <stdarg.h>
#include <stdio.h>
#include <io.h>
//#include <unistd.h>

void	ft_putchar(char c);

void	ft_putstr(char *s);

void	ft_putnbr(int n);

void	ft_low_hex(int n);

void	ft_up_hex(int n);

void	ft_putendl(char *s);

int	ft_atoi(const char *str);

void	print_prm(char prm, va_list ap)
{
	if (prm == 'd')
		ft_putnbr(va_arg(ap, int));
	else if (prm == 'c')
		ft_putchar(va_arg(ap, int));
	else if (prm == 's')
		ft_putstr(va_arg(ap, char *));
	else if (prm == 'p')
	{
		write(1, "0x", 2);
		ft_putnbr(va_arg(ap, int));
	}
	else if (prm == 'x')
		ft_low_hex(va_arg(ap, int));
	else if (prm == 'X')
		ft_up_hex(va_arg(ap, int));
}

int	ft_printf(const char *prm, ...)
{
	int		i;
	va_list	ap;

	i = 0;
	va_start (ap, prm);
	while (prm[i] != '\0')
	{
		if (prm[i] != '%')
			ft_putchar(prm[i]);
		else
		{
			print_prm(prm[i + 1], ap);
			i++;
		}
		i++;
	}
	va_end(ap);
	return (0);
}

int	main(void)
{
	int		d;
	char	c;
	char	*str;
	void		*point;

	d = 16;
	c = 'M';
	str = "This is amasing";
	point = &d;
	//printf("ˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇ\n");
	printf("˯˯˯˯˯˯˯˯˯˯˯˯˯˯˯˯˯\n");
	printf("Decimal %d\nChar %c\nString %s\nPointer %p\nHex %X", \
	d, c, str, (void *)point, 23456);
	printf("\n-----------------\n");
	printf("-----------------\n");
	ft_printf("Decimal %d\nChar %c\nString %s\nPointer %p\nHex %X", \
	d, c, str, (void *)point, 23456);
	printf("\nˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆˆ\n");
}
