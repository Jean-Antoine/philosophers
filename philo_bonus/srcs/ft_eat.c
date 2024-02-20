/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:39:06 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/19 17:48:12 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(int id, t_data *data)
{
	sem_wait(data->forks);
	ft_log(id, data, "has taken a fork");
	sem_wait(data->forks);
	ft_log(id, data, "has taken a fork");
	ft_log(id, data, "is eating");
	sem_wait(data->eating);
	gettimeofday(&(data->last_meal), NULL);
	data->n_meal++;
	sem_post(data->eating);
	usleep(data->time_to_eat * 1000);
	sem_post(data->forks);
	sem_post(data->forks);
}
