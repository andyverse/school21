/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaree <slaree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:38:16 by chfederi          #+#    #+#             */
/*   Updated: 2022/07/22 17:27:41 by slaree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

void	unset_one(char *s, t_data *d)
{
	t_env	*t;

	t = d->env1;
	while (d->env1)
	{
		if (d->env1->next && ft_strncmp(s, d->env1->next->val,
				ft_strlen(s)) == 0)
		{
			free(d->env1->next->val);
			d->env1->next = d->env1->next->next;
			break ;
		}
		if (ft_strncmp(s, d->env1->val, ft_strlen(s)) == 0)
		{
			t = d->env1->next;
			free(d->env1->val);
			free(d->env1);
			d->env1 = t;
		}
		d->env1 = d->env1->next;
	}
	d->env1 = t;
}
