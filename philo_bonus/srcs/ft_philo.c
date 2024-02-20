/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:24:20 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/20 14:33:43 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static

void	ft_philo(int id, t_data *data)
{
	pthread_t	monitor;

	sem_wait()
	data->id = id;
	data->eating = sem_open("eating", O_CREAT, S_IRWXU, 1);
	sem_unlink("eating");
	pthread_create(&monitor, NULL, *ft_monitor, (void *)data);
	if (id % 2)
		usleep(data->time_to_eat);		
	while (1)
	{
		ft_eat(id, data);
		ft_sleep(id, data);
		ft_think(id, data, data->time_to_eat - data->time_to_sleep);
	}
	pthread_join(monitor, NULL);
	ft_free_data(data);
}
