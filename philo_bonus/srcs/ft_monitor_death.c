/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor_death.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:01:03 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/28 16:54:33 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_die(t_philo *philo, t_data *data)
{
	sem_wait(data->print);
	sem_wait(philo->dead);
	ft_send_kill_signal(data);
	if (!philo->stop)
		printf("%8ld %3d %s\n", ft_get_time(data->start),
			philo->id,
			"died");	
	philo->stop = 1;
	sem_post(philo->dead);
	sem_post(data->print);
	sem_post(philo->eating);
	return (NULL);
}

void	*ft_monitor_death(void *args)
{
	t_data	*data;
	t_philo	*philo;
	int		last_meal;

	philo = (t_philo *) args;
	data = philo->data;
	while (!ft_is_dead(philo))
	{
		sem_wait(philo->eating);
		last_meal = ft_get_time(philo->last_meal);
		if (last_meal >= data->args.time_to_die)
			return (ft_die(philo, data));
		sem_post(philo->eating);
	}
	return (NULL);
}
