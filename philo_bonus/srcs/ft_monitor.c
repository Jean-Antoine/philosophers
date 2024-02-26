/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:35:40 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/26 15:07:08 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_die(t_philo *philo, t_data *data)
{
	sem_wait(data->print);
	if (!philo->stop)
		printf("%8ld %3d %s\n", ft_get_time(data->start),
			philo->id,
			"died");
	sem_wait(philo->dead);
	philo->stop = 1;
	sem_post(philo->dead);
	sem_post(data->print);
}

void	*ft_monitor(void *args)
{
	t_data	*data;
	t_philo	*philo;
	int		since_last_meal;
	int		n_meal;
	int		sem_posted;

	philo = (t_philo *) args;
	data = philo->data;
	sem_posted = 0;
	while (!ft_is_dead(philo))
	{
		sem_wait(philo->eating);
		since_last_meal = ft_get_time(philo->last_meal);
		n_meal = philo->n_meal;
		sem_post(philo->eating);
		if (since_last_meal >= data->args.time_to_die)
		{
			ft_die(philo, data);
			ft_send_kill_signal(data);
			return (NULL);
		}
		if (n_meal == data->args.n_meal_needed && !sem_posted)
		{
			sem_posted = 1;
			sem_post(data->all_eaten);
		}
	}
	return (NULL);
}
