/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:39:06 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/28 16:06:44 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo, t_data *data)
{
	sem_wait(data->forks);
	ft_log(philo, data, "has taken a fork");
	sem_wait(data->forks);
	ft_log(philo, data, "has taken a fork");
	sem_wait(philo->eating);
	ft_log(philo, data, "is eating");
	gettimeofday(&(philo->last_meal), NULL);
	philo->n_meal++;
	sem_post(philo->eating);
	ft_usleep(philo, data->args.time_to_eat);
	sem_post(data->forks);
	sem_post(data->forks);
}
