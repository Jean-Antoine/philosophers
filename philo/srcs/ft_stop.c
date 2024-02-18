/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:40:25 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/17 17:43:06 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_set_stop(t_data *data)
{
	pthread_mutex_lock(&(data->stop_m));
	data->stop = 1;
	pthread_mutex_unlock(&(data->stop_m));
}

void	ft_stop(t_philo *philo)
{
	int	n;
	
	ft_set_stop(philo->data);
	n = philo->data->n;
	while (n--)
	{
		if (philo->thread)
			pthread_join(philo->thread, NULL);
		philo = philo->next;
	}
}