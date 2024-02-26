/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:36:38 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/26 11:00:58 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*ft_usage(void)
{
	return ("Usage: ./philo 	[number_of_philosophers] "
		"[time_to_die] [time_to_eat] [time_to_sleep]\n"
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
		"\tphilosopher dies.");
}

void	ft_exit(int msg, t_data *data, t_philo *philo)
{
	if (msg == MSG_INPUT)
		ft_putendl_fd(ft_usage(), 2);
	else if (msg == MSG_NUMERIC)
		ft_putendl_fd("Error: All args must be numeric, strictly "
			"positive and fit into an integer.", 2);
	else if (msg == MSG_MALLOC)
		ft_putendl_fd("Error: malloc()", 2);
	else if (msg == MSG_SEM)
		ft_putendl_fd("Error: sem_open()", 2);
	else if (msg == MSG_FORK)
		ft_putendl_fd("Error: fork()", 2);
	if (data)
		ft_free_data(data);
	if (philo)
		ft_free_philo(philo);
	if (MSG_EMPTY)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}
