/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:24:20 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/28 13:04:49 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo(void *ptr)
{
	t_philo		*philo;

	philo = (t_philo *) ptr;
	if (philo->data->n == 1)
	{
		ft_log("has taken a fork", philo);
		return (NULL);
	}
	if (!(philo->id % 2))
		ft_think(philo, philo->data->time_to_eat);
	if (philo->data->odd && philo->id == 0)
		usleep(philo->data->time_to_eat * 1000);
	while (ft_continue(philo))
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo, philo->data->time_to_think);
	}
	return (NULL);
}
