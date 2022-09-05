/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:45:14 by fnochiza          #+#    #+#             */
/*   Updated: 2021/11/11 18:45:14 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <io.h>

void	ft_putchar(char c);

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}
