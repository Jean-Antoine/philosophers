/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor_eaten_enough.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:02:30 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/26 17:18:18 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_monitor_eaten_enough(void *args)
{
	t_data	*data;
	t_philo	*philo;
	int		n_meal;

	philo = (t_philo *) args;
	data = philo->data;
	while (!ft_is_dead(philo))
	{
		sem_wait(philo->eating);
		n_meal = philo->n_meal;
		sem_post(philo->eating);
		if (n_meal >= data->args.n_meal_needed)
			break ;
	}
	sem_post(data->all_eaten);
	return (NULL);
}
