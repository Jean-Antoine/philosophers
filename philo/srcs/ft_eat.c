/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:39:06 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/16 09:55:38 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static pthread_mutex_t	*ft_first(t_philo *philo)
{
	if (philo->id % 2)
		return (&(philo->fork));
	return (&(philo->next->fork));
}

static pthread_mutex_t	*ft_second(t_philo *philo)
{
	if (philo->id % 2)
		return (&(philo->next->fork));
	return (&(philo->fork));
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(ft_first(philo));
	ft_log("has taken a fork", philo);
	pthread_mutex_lock(ft_second(philo));
	ft_log("has taken a fork", philo);
	ft_log("is eating", philo);
	pthread_mutex_lock(&(philo->started_eating));
	gettimeofday(&(philo->last_meal), NULL);
	philo->n_meal++;
	pthread_mutex_unlock(&(philo->started_eating));
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(ft_second(philo));
	pthread_mutex_unlock(ft_first(philo));
}
