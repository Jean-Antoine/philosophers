/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:20:29 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/15 11:55:03 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_log(char *log, t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->stop_m));
	if (philo->data->stop)
	{
		pthread_mutex_unlock(&(philo->data->stop_m));
		exit(EXIT_SUCCESS);
	}
	pthread_mutex_unlock(&(philo->data->stop_m));
	pthread_mutex_lock(&(philo->data->print));
	printf("%8ld %3d %s\n", ft_get_time(philo->start), philo->id, log);
	pthread_mutex_unlock(&(philo->data->print));
}
