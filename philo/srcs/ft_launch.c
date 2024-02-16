/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:13:01 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/15 18:58:44 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_launch(t_philo *philo)
{
	int		n;

	n = philo->data->n;
	while (n--)
	{
		gettimeofday(&(philo->start), NULL);
		gettimeofday(&(philo->last_meal), NULL);
		pthread_create(&(philo->thread), NULL, *ft_philo, philo);
		philo = philo->next;
	}
	ft_monitor(philo);
	n = philo->data->n;
	while (n--)
	{
		pthread_join(philo->thread, NULL);
		philo = philo->next;
	}
}