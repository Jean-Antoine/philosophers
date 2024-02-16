/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:35:40 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/16 10:29:31 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_set_stop(t_data *data)
{
	pthread_mutex_lock(&(data->stop_m));
	data->stop = 1;
	pthread_mutex_unlock(&(data->stop_m));
}

static int ft_all_eaten(t_philo *philo)
{
	int	n;

	n = philo->data->n;
	while (n--)
	{
		if (philo->n_meal < philo->data->n)
			return (0);
		philo = philo->next;
	}
	return (1);
}

void	ft_monitor(t_philo *philo)
{
	while (!ft_all_eaten(philo))
	{
		philo = philo->next;
		pthread_mutex_lock(&(philo->started_eating));
		if (ft_get_time(philo->last_meal) < philo->data->time_to_die)
		{
			pthread_mutex_unlock(&(philo->started_eating));
			continue ;
		}
		pthread_mutex_unlock(&(philo->started_eating));
		ft_log("died", philo);		
		break ;
	}
	ft_set_stop(philo->data);
}
