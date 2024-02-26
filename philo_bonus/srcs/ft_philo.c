/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:24:20 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/26 15:02:39 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo(int id, t_data *data)
{
	pthread_t	monitor;
	pthread_t	kill;
	t_philo		philo;

	sem_wait(data->kill);
	sem_wait(data->all_eaten);
	ft_init_philo(id, &philo, data);	
	pthread_create(&monitor, NULL, *ft_monitor, (void *)&philo);
	pthread_create(&kill, NULL, *ft_kill, (void *)&philo);
	while (!ft_is_dead(&philo))
	{
		ft_eat(&philo, data);
		ft_sleep(&philo, data);
		ft_think(&philo, data, 0);
	}
	pthread_join(monitor, NULL);
	pthread_join(kill, NULL);
	sem_post(data->all_eaten);
	ft_exit(MSG_EMPTY, data, &philo);
}
