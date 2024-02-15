/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:24:20 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/15 18:58:31 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo(void *ptr)
{
	t_philo		*philo;

	philo = (t_philo *) ptr;
	if (philo->id % 2)
		ft_think(philo, philo->data->time_to_eat);
	while (!ft_stop(philo))
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo,
			philo->data->time_to_sleep - philo->data->time_to_eat);
	}
	return (NULL);
}
