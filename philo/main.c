/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:00:49 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/09 16:30:07 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*philo;

	if (ac < 5 || ac > 6)
		return (ft_exit(NULL));
	philo = NULL;
	if (ft_init_data(ac, av, &data))
		return (1);
	philo = ft_init_philo(&data);
	ft_run_threads(philo);
	ft_free_list(philo);
}
