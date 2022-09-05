/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:28:46 by fnochiza          #+#    #+#             */
/*   Updated: 2022/07/06 20:21:09 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_table	*table;
	t_philo	*philo;

	if (argc < 5 || argc > 6)
		return (0);
	table = malloc(sizeof(t_table));
	if (read_argv(argc, argv, table, 1) == 0 || table_mute_init(table) == 0)
		return (clear_structs(table, NULL));
	philo = create_philo(table);
	if (!philo)
		return (clear_structs(table, NULL));
	if (!create_thread(table, philo))
		return (destroy(table, philo));
	check_terms(philo);
	destroy(table, philo);
}
