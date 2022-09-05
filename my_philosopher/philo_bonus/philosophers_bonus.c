/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:28:46 by fnochiza          #+#    #+#             */
/*   Updated: 2022/07/06 20:30:34 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	main(int argc, char **argv)
{
	t_table	*table;
	int		status;
	int		i;
	int		k;

	k = 0;
	if (argc < 5 || argc > 6)
		return (0);
	table = malloc(sizeof(t_table));
	if (!table)
		return (0);
	if (read_argv(argc, argv, table, 1) == 0)
		exit(3);
	table->ph = create_philo(table);
	semaphore_init(table);
	table->s_time = ft_time();
	create_thread(table);
	waitpid(0, &status, 0);
	i = -1;
	while (++i < table->count)
		kill(table->ph[i].pid, SIGTERM);
	destroy(table, table->ph);
}
