/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:35:40 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/20 14:36:47 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_dead(t_data *data)
{
	sem_wait(data->print);
	printf("%8ld %3d %s\n", ft_get_time(data->start),
		data->id,
		"died");
	ft_exit("", data, DEAD);
}

void	*ft_monitor(void *arg)
{
	t_data	*data;
	int		since_last_meal;
	int		n_meal;
	int		eaten_enough;

	data = (t_data *)arg;
	eaten_enough = 0;
	while (1)
	{
		sem_wait(data->eating);
		since_last_meal = ft_get_time(data->last_meal);
		n_meal = data->n_meal;
		sem_post(data->eating);
		if (since_last_meal > data->time_to_die)
			ft_dead(data);
		if (n_meal == data->n_meal_needed && !eaten_enough)
			sem_post()
	}
}
