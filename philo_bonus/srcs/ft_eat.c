/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:39:06 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/27 16:45:25 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo, t_data *data)
{
	sem_wait(data->forks);
	ft_log(philo, data, "has taken a fork");
	sem_wait(data->forks);
	ft_log(philo, data, "has taken a fork");
	ft_log(philo, data, "is eating");
	sem_wait(philo->eating);
	gettimeofday(&(philo->last_meal), NULL);
	philo->n_meal++;
	sem_post(philo->eating);
	usleep(data->args.time_to_eat * 1000);
	sem_post(data->forks);
	sem_post(data->forks);
}
