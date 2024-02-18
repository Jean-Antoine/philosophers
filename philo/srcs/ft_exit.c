/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:36:38 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/17 13:27:41 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_exit(char *msg)
{
	if (!msg)
		ft_putendl_fd("Usage: ./philo 	[number_of_philosophers] "
			"[time_to_die] "
			"[time_to_eat] "
			"[time_to_sleep]\n"
			"\t\t[number_of_times_each_philosopher_must_eat](optionnal)\n\n"
			"number_of_philosophers:\n"
			"\tThe number of philosophers and also the number of forks.\n"
			"time_to_die (in milliseconds):\n"
			"\tIf a philosopher did not start eating time_to_die\n"
			"\tmilliseconds since the beginning of their last meal or the\n"
			"\tbeginning of the simulation, they die.\n"
			"time_to_eat (in milliseconds):\n"
			"\tThe time it takes for a philosopher to eat.\n"
			"\tDuring that time, they will need to hold two forks.\n"
			"time_to_sleep (in milliseconds):\n"
			"\tThe time a philosopher will spend sleeping.\n"
			"number_of_times_each_philosopher_must_eat (optional argument):\n"
			"\tIf all philosophers have eaten at least\n"
			"\tnumber_of_times_each_philosopher_must_eat times, the simu-\n"
			"\tlation stops. If not specified, the simulation stops when a\n"
			"\tphilosopher dies.", 2);
	else
		ft_putendl_fd(msg, 2);
	return (1);
}
