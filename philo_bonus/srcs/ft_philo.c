/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:24:20 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/27 16:40:32 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_run_monitors(pthread_t *monitor, t_philo *philo)
{
	pthread_create(monitor++, NULL, *ft_monitor_death, (void *) philo);
	pthread_create(monitor++, NULL, *ft_monitor_killed, (void *) philo);
	if (philo->data->args.n_meal_needed > 0)
		pthread_create(monitor, NULL, *ft_monitor_eaten_enough, (void *) philo);
}

static void	ft_join_monitors(pthread_t *monitor, t_philo *philo)
{
	pthread_join(monitor[0], NULL);
	pthread_join(monitor[1], NULL);
	if (philo->data->args.n_meal_needed > 0)
		pthread_join(monitor[2], NULL);
}

void	ft_philo(int id, t_data *data)
{
	pthread_t	monitor[3];
	t_philo		philo;

	sem_wait(data->kill);
	sem_wait(data->all_eaten);
	ft_init_philo(id, &philo, data);
	ft_run_monitors(monitor, &philo);
	if (!(id % 2))
		ft_think(&philo, data, data->args.time_to_eat);
	if (data->args.odd && id == 0)
		usleep(data->args.time_to_eat * 1000);
	while (!ft_is_dead(&philo))
	{
		ft_eat(&philo, data);
		ft_sleep(&philo, data);
		ft_think(&philo, data, data->args.time_to_think);
	}
	ft_join_monitors(monitor, &philo);
	ft_exit(MSG_EMPTY, data, &philo);
}
