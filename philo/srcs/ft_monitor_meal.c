/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor_meal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:45:11 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/28 15:54:21 by jeada-si         ###   ########.fr       */
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

static int	ft_eaten_enough(int n, t_philo *philo)
{
	while (n--)
	{
		if (ft_n_meal(philo) < philo->data->n_meal_needed)
			return (0);
		philo = philo->next;
	}
	return (1);
}

void	*ft_monitor_meal(void *args)
{
	t_philo	*philo;

	philo = (t_philo *) args;
	if (philo->data->n_meal_needed == -2)
		return (NULL);
	while (ft_continue(philo))
	{
		if (!ft_eaten_enough(philo->data->n, philo))
			continue ;
		ft_send_kill_signal(philo->data);
		break ;
	}
	return (NULL);
}
