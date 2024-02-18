/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:24:20 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/18 17:32:55 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo(int id, t_data *data)
{
	free(data->philo);
	data->id = id;
	// if (data->n == 1)
	// {
	// 	ft_log("has taken a fork", philo);
	// 	exit (EXIT_SUCCESS);
	// }
	while (ft_continue(philo))
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo, philo->data->time_to_eat - philo->data->time_to_sleep);
	}
	return (NULL);
}
