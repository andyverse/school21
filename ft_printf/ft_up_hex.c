/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:45:06 by fnochiza          #+#    #+#             */
/*   Updated: 2021/11/11 18:45:06 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_up_hex(int n)
{
	int			i;
	char		num[12];
	char		*hex;
	long int	nn;

	hex = "0123456789ABCDEF";
	i = 0;
	if (n == 0)
		return (ft_putchar('0'));
	nn = (long int)n;
	if (nn < 0)
	{
		ft_putchar('-');
		nn = nn * (-1);
	}
	while (nn != 0)
	{
		num[i] = hex[nn % 16];
		i++;
		nn = nn / 16;
	}
	i--;
	while (i >= 0)
		ft_putchar(num[i--]);
}

// int main (void)
// {
// 	int i = 235436;
// 	ft_up_hex(i);
// }
