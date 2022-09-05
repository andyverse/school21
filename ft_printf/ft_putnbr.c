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

#include <io.h>

void	ft_putchar(char c);

void	ft_putnbr(unsigned long long n)
{
	int			i;
	char		num[12];
	long int	nn;

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
		num[i] = nn % 10 + '0';
		i++;
		nn = nn / 10;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar(num[i]);
		i--;
	}
}
