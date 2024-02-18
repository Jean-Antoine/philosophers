/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:35:40 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/18 12:29:48 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_n_meal(t_philo *philo)
{
	int	n_meal;

	pthread_mutex_lock(&(philo->started_eating));
	n_meal = philo->n_meal;
	pthread_mutex_unlock(&(philo->started_eating));
	return (n_meal);
}

static int	ft_last_meal(t_philo *philo)
{
	int	last_meal;

	pthread_mutex_lock(&(philo->started_eating));
	last_meal = ft_get_time(philo->last_meal);
	pthread_mutex_unlock(&(philo->started_eating));
	return (last_meal);
}

static int	ft_all_eaten_enough(t_philo *philo)
{
	int	n;

	if (philo->data->n_meal_needed == -2)
		return (0);
	if (ft_get_time(philo->data->start) < philo->data->n_meal_min_time)
		return (0);
	n = philo->data->n;
	while (n--)
	{
		if (ft_n_meal(philo) < philo->data->n_meal_needed)
			return (0);
		philo = philo->next;
	}
	return (1);
}

void	ft_monitor(t_philo *philo)
{
	while (!ft_all_eaten_enough(philo))
	{
		philo = philo->next;
		if (ft_last_meal(philo) < philo->data->time_to_die)
			continue ;
		ft_log("died", philo);
		return ;
	}
}
