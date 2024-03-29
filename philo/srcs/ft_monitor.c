/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:35:40 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/28 15:53:32 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_is_alive(t_philo *philo)
{
	pthread_mutex_lock(&(philo->started_eating));
	if (ft_get_time(philo->last_meal) > philo->data->time_to_die)
		return (0);
	pthread_mutex_unlock(&(philo->started_eating));
	return (1);
}

void	ft_monitor(t_philo *philo)
{
	pthread_t	monitor_meal;

	pthread_create(&monitor_meal, NULL, ft_monitor_meal, (void *) philo);
	while (ft_continue(philo))
	{
		philo = philo->next;		
		if (ft_is_alive(philo))
			continue ;
		ft_log("died", philo);
		ft_send_kill_signal(philo->data);
		pthread_mutex_unlock(&(philo->started_eating));
		break ;
	}
	pthread_join(monitor_meal, NULL);
}
