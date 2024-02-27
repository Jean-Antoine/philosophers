/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor_killed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:01:32 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/27 10:23:34 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_wait_kill_signal(t_data *data)
{	
	sem_wait(data->kill);
	sem_post(data->kill);
}

void	*ft_monitor_killed(void *args)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *) args;
	data = philo->data;
	ft_wait_kill_signal(data);
	sem_wait(data->print);
	sem_wait(philo->dead);
	philo->stop = 1;
	sem_post(philo->dead);
	sem_post(data->print);
	sem_post(data->all_eaten);
	sem_post(data->pre_fork);
	sem_post(data->forks);
	sem_post(data->forks);
	return (NULL);
}
