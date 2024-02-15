/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:35:40 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/15 18:55:46 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_monitor(t_philo *philo)
{
	while (1)
	{
		philo = philo->next;
		pthread_mutex_lock(&(philo->started_eating));
		if (ft_get_time(philo->last_meal) < philo->data->time_to_die)
		{
			pthread_mutex_unlock(&(philo->started_eating));
			continue ;
		}
		pthread_mutex_unlock(&(philo->started_eating));
		pthread_mutex_lock(&(philo->data->stop_m));
		philo->data->stop = 1;
		pthread_mutex_unlock(&(philo->data->stop_m));
		pthread_mutex_lock(&(philo->data->print));
		printf("%8ld %3d %s\n", ft_get_time(philo->start), philo->id, "died");
		pthread_mutex_unlock(&(philo->data->print));
		return ;
	}
}
