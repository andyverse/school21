#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;

	if (fd < 0)
		return ;
	un = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		un = -n;
	}
	if (un >= 10)
	{
		ft_putnbr_fd(un / 10, fd);
		ft_putchar_fd((un % 10) + '0', fd);
	}
	else
		ft_putchar_fd(un + '0', fd);
}
