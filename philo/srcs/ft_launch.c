/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:13:01 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/18 12:50:13 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_launch(t_philo *philo)
{
	int				n;

	n = philo->data->n;
	gettimeofday(&(philo->data->start), NULL);
	while (n--)
	{
		philo->last_meal.tv_sec = philo->data->start.tv_sec;
		philo->last_meal.tv_usec = philo->data->start.tv_usec;
		if (pthread_create(&(philo->thread), NULL, *ft_philo, philo))
			return ;
		philo = philo->next;
	}
	ft_monitor(philo);
}
